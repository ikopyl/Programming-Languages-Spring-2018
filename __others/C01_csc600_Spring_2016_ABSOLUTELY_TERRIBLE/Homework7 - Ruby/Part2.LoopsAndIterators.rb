=begin
2. Write a Ruby demo program that illustrates the use of all main Ruby loops and iterators.
=end

x = 1

#while-do
puts "While-do: "
while 5 >= x do
	puts x
	x += 1
end

#while modifier
puts "\nWhile modifier: "
begin
	puts x
	x += 1
end while x <= 10


#until-do
puts "\nUntil-do: "
until x > 15 do
	puts x
	x += 1
end

#until modifier
puts "\nUntil modifier: "
begin
	puts x
	x += 1
end until x > 20

#loop-do
puts "\nloop do"
loop do
	puts x
	x+=1
	break if x == 26
end
puts

#for
puts "\nFor loop"
for x in 26..30
	puts x
end

#upto
puts "\nupto"
	x.upto(35) {|y| puts y}

#downto
puts "\ndownto"
	x.downto(25) {|y| puts y}

#times (implicit/explicit counter)
puts "\ntimes"
5.times {|y| puts y + 1}

#each
array = [1,"x",2,"y",5]
puts "\neach"
array.each do |y|
	puts y
end

#map
puts "\nmap"
array.map{|y| puts y}

#step
puts "\nstep"
(15..45).step(3) do |i|
	puts i
end



