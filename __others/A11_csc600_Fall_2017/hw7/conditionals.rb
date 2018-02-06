#############
#HW7.1 Demo program for conditional statements
#############
a = 6
print "a = ", a.to_s
puts
#if else statement
#then is optional
if a < 0 then
	puts "#{a} is a negative integer"
elsif a > 0
	puts "#{a} is a positive integer"
else
	puts "#{a} is 0"
end
#if modifier
puts "a is not 0" if a != 0

#unless statement
unless a%2 == 0
	puts "#{a} is odd"
else
	puts "#{a} is even"
end
#unless modifier
puts "a is not 0" unless a == 0

#case statement
case a
when 0..9
	puts "#{a} is a single digit integer"
when 10..99
	puts "#{a} is a double digit integer"
else
	puts "#{a} is either more than three digits or negative"
end

#ternary operator
str = a == 0?
	"a is 0" : "a is not 0"
puts str