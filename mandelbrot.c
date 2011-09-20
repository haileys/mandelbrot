#include <stdlib.h>
#include <stdbool.h>
#include <complex.h>
#include "ruby.h"

static ID i_Complex = Qundef;
static ID i_to_f = Qundef;
static ID i_INFINITY = Qundef;

static VALUE Float_INFINITY = Qundef;
static VALUE Mandelbrot = Qundef;
static VALUE Mandelbrot_initialize(int argc, VALUE* argv, VALUE self);
static VALUE Mandelbrot_compute(VALUE self, VALUE _width, VALUE _height);

static double rb_complex_re(VALUE cplx)
{
    _Complex ret;
    VALUE tmp = Qnil;
    rb_check_type(cplx, T_COMPLEX);
    
    tmp = rb_funcall(RCOMPLEX(cplx)->real, i_to_f, 0);
    return NUM2DBL(tmp);
}

static double rb_complex_im(VALUE cplx)
{
    _Complex ret;
    VALUE tmp = Qnil;
    rb_check_type(cplx, T_COMPLEX);
    
    tmp = rb_funcall(RCOMPLEX(cplx)->imag, i_to_f, 0);
    return NUM2DBL(tmp);
}

void Init_mandelbrot()
{
    i_Complex = rb_intern("Complex");
    i_to_f = rb_intern("to_f");
    i_INFINITY = rb_intern("INFINITY");
    Float_INFINITY = rb_const_get(rb_cFloat, i_INFINITY);
    
    Mandelbrot = rb_define_class("Mandelbrot", rb_cObject);
    rb_define_method(Mandelbrot, "initialize", Mandelbrot_initialize, -1);
    rb_define_method(Mandelbrot, "compute", Mandelbrot_compute, 2);
    rb_define_attr(Mandelbrot, "min", true, false);
    rb_define_attr(Mandelbrot, "max", true, false);
    rb_define_attr(Mandelbrot, "max_iters", true, true);
}

static VALUE Mandelbrot_initialize(int argc, VALUE* argv, VALUE self)
{
    VALUE min, max;
    rb_scan_args(argc, argv, "02", &min, &max);
    
    if(NIL_P(min)) {
        min = rb_funcall(rb_mKernel, i_Complex, 2, DBL2NUM(-1), DBL2NUM(-1));
    }
    if(NIL_P(max)) {
        max = rb_funcall(rb_mKernel, i_Complex, 2, DBL2NUM(1), DBL2NUM(1));
    }
    
    rb_check_type(min, T_COMPLEX);
    rb_check_type(max, T_COMPLEX);
    
    rb_iv_set(self, "@min", min);
    rb_iv_set(self, "@max", max);
    rb_iv_set(self, "@max_iters", INT2NUM(128));
    
    return Qnil;
}

static VALUE Mandelbrot_compute(VALUE self, VALUE _width, VALUE _height)
{    
    double min_re, min_im, max_re, max_im;
    double x0, y0, re, im, retemp;
    int width, height;
    int max_iters;
    int x, y, iter;
    VALUE ary, col, tmp;
    VALUE r_min;
    VALUE r_max;
    
    rb_check_type(_width, T_FIXNUM);
    rb_check_type(_height, T_FIXNUM);
    width = NUM2INT(_width);
    height = NUM2INT(_height);
    
    r_min = rb_iv_get(self, "@min");
    r_max = rb_iv_get(self, "@max");
    min_re = rb_complex_re(r_min);
    min_im = rb_complex_im(r_min);
    max_re = rb_complex_re(r_max);
    max_im = rb_complex_im(r_max);
    
    max_iters = NUM2INT(rb_iv_get(self, "@max_iters"));
    
    ary = rb_ary_new();
    for(x = 0; x < width; x++) {
        col = rb_ary_new();
        rb_ary_push(ary, col);
        for(y = 0; y < height; y++) {
            x0 = (max_re - min_re) * ((double)x / (double)width) + min_re;
            y0 = (max_im - min_im) * ((double)y / (double)height) + min_im;
            re = 0;
            im = 0;
            for(iter = 0; iter < max_iters && (re*re + im*im < 2*2); iter++) {
                retemp = re*re - im*im + x0;
                im = 2*re*im + y0;
                re = retemp;
            }
            if(x*x + y*y < 2*2) {
                rb_ary_push(col, Float_INFINITY);
            } else {
                rb_ary_push(col, INT2NUM(iter));
            }
        }
    }
    
    return ary;
}