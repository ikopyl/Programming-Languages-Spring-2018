=begin
4. Write a function sort(v) that returns the sorted array v. Do not use Ruby sort methods; write your own sort. Array v must remain unchanged.
=end

#BubbleSort
def sort(v)
  n = v.length
  loop do
    swapped = false

    (n-1).times do |i|
      if v[i] > v[i+1]
        v[i], v[i+1] = v[i+1], v[i]
        swapped = true
      end
    end

    break unless swapped
  end
end

v = [11,425,12,76,93,50,289]
puts "\nunsorted array:"
for x in v do print x, ", " end
sort(v)
puts "\n\nsorted array: "
for x in v do print x, ", " end
puts "\n\n"


