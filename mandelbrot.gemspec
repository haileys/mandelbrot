Gem::Specification.new do |s|
  s.name        = "mandelbrot"
  s.version     = "0.1"
  s.date        = "2011-09-20"
  s.summary     = "A Ruby C extension for rendering Mandelbrot fractals"
  s.authors     = ["Charlie Somerville"]
  s.email       = "charlie@charliesomerville.com"
  s.files       = Dir["ext/**/*.{c,h,rb}"] + ["lib/mandelbrot.rb"]
  s.extensions  = "ext/mandelbrot/extconf.rb"
  s.homepage    = "https://github.com/charliesome/mandelbrot"
end