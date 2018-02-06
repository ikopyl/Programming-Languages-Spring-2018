#############
#HW7.2 Demo program for loops and iterators
#############

###loops###
#while-do
a = 1
while a < 10 do
	print "#{a} "
	a *= 2
end
puts

#until-do 
until a == 0 do
	print "#{a} "
	a /= 2
end
puts

#for-in
hash = {1 => "fire", 2 => "water", 3 => "grass"}
for key,var in hash
	puts "#{key} => #{var}"
end

###iterators###
#upto
1.upto(3){|counter| a += counter; print "#{a} "}
puts
#downto
5.downto(1){|counter| print "#{counter} "}
puts

#times
a.times{print "hi "}
puts

#each
hash.each{|component| puts component}
puts

#map
sum = 0
(1..5).map{|x| puts (x*x)}
puts

#step
1.step(2,0.2) do |x| print "#{x} " end
puts

#collect
squares = [1,2,3].collect{|x| x**2}
puts squares
puts

#select
odds = (1..5).select{|x| x%2 == 1}
puts odds
puts

#reject
evens = (1..5).reject{|x| x%2 == 1}
puts evens
puts

