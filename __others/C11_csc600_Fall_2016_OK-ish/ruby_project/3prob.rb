def mean_sigma(v)
	sum=0
	dev=0
	for item in v #Calculate sum
		sum += item
	end
	mean = sum/v.length
	
	for item in v #Calculate deviation
		dev += (item - mean)*(item - mean)
	end
	dev = Math.sqrt(dev/2)

	return mean , dev
end

result = mean_sigma([1,2,3,4,5])

printf("Mean is: %d \nDeviation is: %.3f\n",result[0],result[1])


