= .loop

(from ruby core)
=== Implementation from Kernel
------------------------------------------------------------------------------
  loop { block }
  loop            -> an_enumerator

------------------------------------------------------------------------------

Repeatedly executes the block.

If no block is given, an enumerator is returned instead.

  loop do
    print "Input: "
    line = gets
    break if !line or line =~ /^qQ/
    # ...
  end

StopIteration raised in the block breaks the loop.  In this case, loop returns
the "result" value stored in the exception.

  enum = Enumerator.new { |y|
    y << "one"
    y << "two"
    :ok
  }

  result = loop {
    puts enum.next
  } #=> :ok


(from gem parser-2.5.1.0)
=== Implementation from Default
------------------------------------------------------------------------------
  loop(type, keyword_t, cond, do_t, body, end_t)

------------------------------------------------------------------------------

Loops