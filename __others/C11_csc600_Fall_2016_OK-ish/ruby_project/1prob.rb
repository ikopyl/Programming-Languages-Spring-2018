num1 = 4
num2 = 9

printf("Num 1 = %d\nNum 2 = %d\n",num1,num2)
#IF THEN
if num1 == 4 then
	puts "Num 1 is 4"
end
#IF ELSE
if num2 == 4 then
	puts "Num 2 is 4"
else
	puts "Num 2 is not 4"
end
#IF ELSIF ELSE
if num1 < num2 then
	puts "Num 2 is greater than Num 1"
elsif num1 > num2 then
	puts "Num 1 is greater than Num 2"
else
	puts "Num 1 equals Num 2"
end
#UNLESS
unless num1 > 5
	puts "Num 1 is small"
end
#UNLESS ELSE
unless num2 > 5 
	puts "Num 2 is small" 
else
	puts "Num 2 is big"
end
#UNLESS MODIFIER
puts "Num 1 is small" unless num1 > 5
#IF MODIFIER
puts "Num 2 is big" if num2 > 5

#Case
case num1
when 1
	puts("Num 1 is 1")
when 2
	puts("Num 1 is 2")
when 3
	puts("Num 1 is 3")
when 4
	puts("Num 1 is 4")
when 5
	puts("Num 1 is 5")
else
	puts("Num is not between 1 and 5")
end
