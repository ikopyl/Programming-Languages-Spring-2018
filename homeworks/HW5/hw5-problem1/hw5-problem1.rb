def generate_new_rand_int_arr(n=100, upper_bound=10)
  n.times.map { rand(upper_bound + 1) }
end

p generate_new_rand_int_arr
