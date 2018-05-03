def generate_new_rand_int_arr(size = 100, val_upper_bound = 10)
  Array.new(size) { rand(val_upper_bound + 1) }
end

p generate_new_rand_int_arr
