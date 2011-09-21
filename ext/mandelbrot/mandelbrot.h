#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "bmp.h"
#include "ruby.h"

static VALUE Float_INFINITY = Qundef;
static VALUE Mandelbrot = Qundef;
static VALUE Mandelbrot_initialize(int argc, VALUE* argv, VALUE self);
static VALUE Mandelbrot_compute(VALUE self, VALUE _width, VALUE _height);
static VALUE Mandelbrot_bmp(VALUE self, VALUE _width, VALUE _height);

int* mandelbrot_compute(int w, int h, double min_re, double min_im, double max_re, double max_im, int max_iter);