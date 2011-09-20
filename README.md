# mandelbrot

A Ruby C extension for rendering mandelbrots.

## Compilation

    ruby extconf.rb
    make

(yeah yeah, I'll make this into a proper gem later...)

## It's super easy to use...

    require './mandelbrot'
    m = Mandelbrot.new Complex(-2, -1), Complex(1, 1)
    grid = m.render 1680, 1050

## Example

![generation is super quick](http://i.imgur.com/7S4Bj.png)

![the output is very pretty](http://i.imgur.com/tx6Ky.png)