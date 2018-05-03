def generate_rand_int_array(size = 100, val_upper_bound = 10)
  Array.new(size) { rand(val_upper_bound + 1) }
end

def show(array)
  print 'Array is empty' if array.empty?
  array.each { |item| print item, ' ' } unless array.empty?
  puts
end

def hist(array)
  array.each do |item|
    print item, '\t'
    item.times { print '*' }
    puts
  end
end
