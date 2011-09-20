require './mandelbrot'

arr = Mandelbrot.new(Complex(-2, -1), Complex(1, 1)).compute(300, 200)

puts "<style>* { margin:0px; padding:0px; }</style>"
arr.each do |col|
  puts "<div style='width:4px;float:left;'>"
  col.each do |cell|
    puts "<div style='height:4px;width:4px;background:#{cell == Float::INFINITY ? "black" : "rgb(#{cell}, #{cell}, #{cell})"}'>&nbsp;</div>"
  end
  puts "</div>"
end