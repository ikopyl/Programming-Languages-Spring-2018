#lang scheme

; problem 1a: show an example of the anonymous function and its use

(define (add-num-to-each-element-in-list num lst)
  (map (lambda (x) (+ x num)) lst))


; problem 1b: show examples of defining and using named functions


; problem 1c: show an example of a data structure (e.g. a list) that contains functions


; problem 1d: show an example of comparing functions and lists for equality


; problem 1e: show an example of passing function as an argument to another function


; problem 1f: show an example of returning a function as a result of another function


; problem 1g: show examples of:
;    reading function(s) from the keyboard,
;    reading function(s) from a file,
;    and displaying a function