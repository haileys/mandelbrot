# mandelbrot

A Ruby C extension for rendering the Mandelbrot set.

## Installation

    gem install mandelbrot

## It's super easy to use...

    require './mandelbrot'
    m = Mandelbrot.new Complex(-2, -1), Complex(1, 1)
    grid = m.render 1680, 1050
    
You can also set the max number of iterations:

    m.max_iters = 1024
    
And render a Bitmap Image:

    m.bmp 1680, 1050

## Example

![generation is super quick](http://i.imgur.com/7S4Bj.png)

![the output is very pretty](http://i.imgur.com/tx6Ky.png)