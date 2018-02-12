#############
#HW7.6 Write recognizer methods limited? and sorted?
#that expands the Ruby class Array
#############
class Array
	def limited?(amin,amax)
		self.each do |x|
			unless amin <= x and x <= amax 
				return false
			end
		end
		return true
	end

	#returns 0 if not sorted, +1 if increasing, -1 if decreasing
	def sorted?
		if self.length > 1
			if self[0] >= self[1]
				#decreasing
				if self.length > 2
					(2..self.length-1).each do |i|
						unless self[i-1] >= self[i]
							return 0
						end
					end
				end
				return +1
			else
				#increasing
				if self.length > 2
					(2..self.length-1).each do |i|
						unless self[i-1] <= self[i]
							return 0
						end
					end
				end
				return -1
			end
		end
	end
end

#Sample tests
arr = [6,8,2,6]
p arr
puts arr.limited?(0,10)
puts arr.sorted?
arr = arr.sort
p arr
puts arr.sorted?
arr = arr.reverse
p arr
puts arr.sorted?