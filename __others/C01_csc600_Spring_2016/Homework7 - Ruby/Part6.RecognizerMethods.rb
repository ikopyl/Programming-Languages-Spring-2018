=begin
6. Write Ruby recognizer methods limited? and sorted? that expand 
the Ruby class Array. The expression array.limited?(amin,amax) should 
return true if amin ≤ a[i] ≤ amax for all values of i. The expression 
array.sorted? should return
• 0 	if the array is not sorted
• +1 	if a[0] ≤ a[1] ≤ a[2] ≤ ... (increasing sequence)
• -1  	if a[0] ≥ a[1] ≥ a[2] ≥ ... (decreasing sequence)
Show examples of the use of this method.
=end

class Array

	#Returns true if all value amin ≤ a[i] ≤ amax for all values of i in array.
	def limited?(amin,amax)
		i=0
		begin
			if self[i]<=amax && self[i]>=amin
				return "true"
			end
			i+=1
		end until self.size <= i
	end

	#checks if the array is sorted, if yes, in increasing or decreasing order.
	def sorted?
		0.upto self.length do |i|
			if self[i] >= self[i+1] then
				return "-1"
			elsif self[i] <= self[i+1]
				return "+1"
			else
				return "0"
			end
		end
	end
end

array = Array.new
array = [11,425,12,76,93,50,289]
#parameters(amin,amax)
puts array.limited?(11, 425)
puts array.sorted?

