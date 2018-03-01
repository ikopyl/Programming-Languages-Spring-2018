#############
#HW7.3 Write a function mean_sigma(v) that returns two values,
#the mean value and the st. dev of numbers in array v
#############
def mean_sigma(v)
	sum1 = 0.0
	for x in v do sum1 += x end
	mean = sum1/v.length
	sum2 = 0.0
	for x in v do sum2 += (x - mean)**2 end
	stdev = Math::sqrt(sum2/v.length)
	return mean, stdev
end

#Sample test
array = [9, 2, 5, 4, 12, 7, 8, 11, 9, 3, 7, 4, 12, 5, 4, 10, 9, 6, 9, 4]
puts mean_sigma(array)