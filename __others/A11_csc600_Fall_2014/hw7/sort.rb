#############
#HW7.4 Write a function sort(v) without using ruby sort methods
#returns sorted array v but the original array should not be changed
#############
def sort(v)
	arr = Array.new(v)
	(1...v.length).each do |i|
      j = i
      while j > 0 and arr[j-1] > arr[j]
          arr[j], arr[j-1] = arr[j-1], arr[j]
          j -= 1
      end
    end
	return arr
end

#Sample test
array = [9, 2, 5, 4, 12, 7, 8, 11, 9, 3, 7, 4, 12, 5, 4, 10, 9, 6, 9, 4]
sorted = sort(array)
puts "array"
array.each{|x| print "#{x} "}
puts
puts "sorted"
sorted.each{|x| print "#{x} "}
puts
puts "original array"
array.each{|x| print "#{x} "}
puts
