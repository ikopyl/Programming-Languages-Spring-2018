i=0
a = [1,2,3,4]

#loop do
loop do 
	break if i=5
	i = i+1
end
puts i
#while do
while i > 0 do
	i = i-1
end
puts i
#Until do
until i = 10 do
	i= i+1
end
puts i
# While Modifier
i = i+1 while i<20
puts i
#until modifier
i = i-1 until i < 1
puts i

for item in a
	print item
end
puts

(0).upto(6){|n| print  n}
puts

#Times
3.times{ print "hi "};puts
n=2
#Times implicit variable
n.times{ print "hello "};puts
n=6
#Times Explicit variable
n.times{|t| print t};puts

#Each
a.each{|item| print item}
puts

#Map
[1,2,3].map{|x| print(5*x, " ")};puts

#Step
0.step(50,5) do |x| print(x," ") end 
puts