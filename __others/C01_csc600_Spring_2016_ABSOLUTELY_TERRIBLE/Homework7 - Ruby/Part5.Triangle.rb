=begin
5. Create a Ruby class triangle with initalizer, accessors, and member 
functions for computing the perimeter and the area of arbitrary triangles. 
Make also a member function test that checks sides a, b, and c and classifies 
the triangle as (1) equilateral, (2) isosceles, (3) scalene, (4) right, 
and (5) not a triangle. Right triangle can be either isosceles or scalene. 
Compute the perimeter and area only for valid triangles (verified by test). 
Show examples of the use of this class.
=end

class Triangle 
	def initialize(a,b,c)
		@a, @b, @c = a,b,c
	end
	
	#Checks for Triangle type with the lengths of 3 given sides.
	def test
		type=" "
		if @a+@b<@c||@a-@b>@c
			type = "invalid triangle" 
		elsif @a**2+@b**2==@c**2||@a**2+@c**2==@b**2||@b**2+@c**2==@a**2
			type = "Right Triangle"
		elsif @a==@b && @a==@c
			type= "Equilateral" 
		elsif @a==@b||@b==@c||@c==@a
			type="Isosceles"
		else type = "Scalene"
		end
		
		return type		
	end
	
	#Calculates Perimeter of Triangle
	def perimeter()
			perimeter = @a+@b+@c 
	end
	
	#Calculates Area of Triangle
	def area()
		s=0.5*(@a+@b+@c)
			area = Math.sqrt(s*(s-@a)*(s-@b)*(s-@c))

	end
end

#RIGHT TRIANGLE
a, b, c = 6, 8, 10
triangle = Triangle.new(a, b, c)
print "\nTYPE:      ", triangle.test
print "\nPERIMETER: ", triangle.perimeter()
print "\nAREA:      ", triangle.area()

#SCALENE
a, b, c = 2, 5, 6
triangle2 = Triangle.new(a, b, c)
print "\n\nTYPE:      ", triangle2.test
print "\nPERIMETER: ", triangle2.perimeter()
print "\nAREA:      ", triangle2.area()

#ISOOSCELES
a, b, c = 6, 10, 10
triangle4 = Triangle.new(a, b, c)
print "\n\nTYPE:      ", triangle4.test
print "\nPERIMETER: ", triangle4.perimeter()
print "\nAREA:      ", triangle4.area(), "\n\n"