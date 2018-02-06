#############
#HW7.5 Write a class triangle with initializer, accessors
#and member functions perimeter, area, test
#############
class Triangle
	def initialize(x,y,z)
		@a = x
		@b = y
		@c = z
	end

	#Getters
	def a
		@a
	end

	def b
		@b
	end

	def c
		@c
	end

	#Setters
	def a=(x)
		@a = x
	end

	def b=(y)
		@b = y
	end

	def c=(z)
		@c = z
	end

	#Functions
	#Test checks if the triangle is (1)equilateral, (2)isosceles, 
	#(3)scalene, (4)right, and (5)not a triangle.
	def test
		var = if @a >= @b+@c or @b >= @a+@c or @c >= @b+@a then 5
		elsif @a == @b and @a == @c then var = 1
		elsif @a**2 == @b**2 + @c**2 or @b**2 == @a**2 + @c**2 or
			@c**2 == @b**2 + @a**2 then var = 4
		elsif @a == @b or @a == @c or @b == @c then var = 2
		else var = 3
		end

		return var
	end

	def perimiter
		if self.test == 5
			puts "Not a triangle!"
		 	return
		end
		return @a+@b+@c
	end

	def area
		if self.test == 5
			puts "Not a triangle!"
		 	return
		end
		p = self.perimiter/2
		return Math::sqrt(p*(p-@a)*(p-@b)*(p-@c))
	end

end

#Sample test
#print result of test given Triangle t
def ptest(t)
	case t.test
	when 1
		return "is an equilateral triangle"
	when 2
		return "is an isosceles triangle"
	when 3
		return "is a scalene triangle"
	when 4
		return "is a right triangle"
	when 5
		return "is not a triangle"
	else
		return "error"
	end
end
t1 = Triangle.new(3,4,5)
p t1
print "t1: a = #{t1.a}, b = #{t1.b}, c = #{t1.c}, t1 ", ptest(t1)
puts
puts "perimiter: #{t1.perimiter}, area #{t1.area}"
t1.c= 2
print "t1: a = #{t1.a}, b = #{t1.b}, c = #{t1.c}, t1 ", ptest(t1)
puts
t1.b= 3
print "t1: a = #{t1.a}, b = #{t1.b}, c = #{t1.c}, t1 ", ptest(t1)
puts
t1.c= 3
print "t1: a = #{t1.a}, b = #{t1.b}, c = #{t1.c}, t1 ", ptest(t1)
puts
t1.a= 9
print "t1: a = #{t1.a}, b = #{t1.b}, c = #{t1.c}, t1 ", ptest(t1)
puts
