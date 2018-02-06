class Triangle

	def initialize(a,b,c)
		@first = a
		@second = b
		@third = c
	end
	
	def get_first()
		@fisrt
	end
	
	def get_second()
		@second
	end
	
	def get_third()
		@third
	end	
	
	def perimeter
		@first+@second+@third
	end
	
	def nottri
		if (@first+@second)<@third or (@first+@third)<@second or (@second+@third)<@first then 
			return true
		else
			return false
		end
	end
	
	def test
		if nottri
			return 5
		elsif @first==@second and @second==@third then 
			return 1
		elsif @first!=@second and @second!=@third and @first!=@third then
			return 3
		else
			return 2
		end
	end	
end

a= Triangle.new(4,4,4)
print "type ", a.test;puts
a= Triangle.new(4,5,4)
print "type ", a.test;puts
a= Triangle.new(3,5,4)
print "type ", a.test;puts
a= Triangle.new(1,1,4)
print "type ", a.test;puts