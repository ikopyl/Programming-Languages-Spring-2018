=begin
3. Write a function mean_sigma(v) that returns two values: the mean value and the standard deviation of numbers stored in the array v 
=end

	def mean_sigma(v)
			mean = v.inject(0){|i,j| i+j}/v.length.to_f
			sum = v.inject(0){|i,j| i + (j-mean)**2}
			stdDev = Math.sqrt(1/v.length.to_f*sum)
			return mean, stdDev
	end

v = [11,425,12,76,93,50,289]
puts mean_sigma(v)
