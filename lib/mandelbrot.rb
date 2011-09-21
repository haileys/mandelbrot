require 'mandelbrot/mandelbrot'

class Mandelbrot
  def inspect
    "#<Mandelbrot min=#{min.inspect}, max=#{max.inspect}, max_iters=#{max_iters}>"
  end
end