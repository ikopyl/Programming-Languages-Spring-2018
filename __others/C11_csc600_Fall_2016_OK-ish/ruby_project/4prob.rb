def sort(v)
	a=[]	
	v.each{|i| a.push(i)}
	0.upto((a.length)-1) do |n|
		min=n
		n.upto((a.length)-1) do |x|
			min=x if (a[x].to_s.to_i < a[n].to_s.to_i)
		end
		t=a[n]
		a[n] = a[min] #USING a[n]=a[min],a[min]=a[n] caused wrong vals
		a[min] = t	
	end
	return a
end

sorted = sort([3,2,5,6,4])
sorted.each{|i| print i};puts