=begin
1. Write a Ruby demo program that illustrates the use of all 
main Ruby conditional statements.
=end

x = 5
y = 5

#if-then
if x = y 
	then puts "x and y are equal" 
end


#if-else
if (x+y == 10)
	puts "The sum of x and y is 10"
else
	puts "The sum of x and y is not 10"
end

#if-elsif
z = 11
if z > y
	puts "z is greater than the sum of x and y"
elsif z < x
	puts "z is less than the sum of x and y"
else
	puts "z is equal to the sum of x and y"
end

#unless
unless x+y>z
	puts "z is greater than or equal to the sum of x and y"
else
	puts "z is less than the sum of x and y"
end

#modifiers
puts "z > x+y" if z > x+y
puts "x+y > z" unless z >x+y

#case
finalGrade = 72
letterGrade = case finalGrade
	when 0..59 then "F"
	when 60..69 then "D"
	when 70..79 then "C"
	when 80..89 then "B"
	when 90..100 then "A"
	end
puts "Final Grade: " + letterGrade