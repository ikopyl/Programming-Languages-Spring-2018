#lang racket

; problem 1a: show an example of the anonymous function and its use

(define (add-num-to-each-element-in-list num lst)
  (map (lambda (x) (+ x num)) lst))


; problem 1b: show examples of defining and using named functions


; problem 1c: show an example of a data structure (e.g. a list) that contains functions


; problem 1d: show an example of comparing functions and lists for equality







; problem 1e: show an example of passing function as an argument to another function

(define (square x)
    (* x x))

(define (double x)
    (* x 2))

(define (atom? x)
  (and (not (pair? x))
       (not (null? x))))

(define (conveyor lst-functions lst-data-operand1)
    (cond
      [(empty? lst-functions) lst-data-operand1]
      [(atom? lst-functions) ((map lst-functions lst-data-operand1))]
      [else (conveyor (cdr lst-functions)
                      (if (procedure? (car lst-functions))
                          (map (car lst-functions) lst-data-operand1)
                          (map (eval (car lst-functions)) lst-data-operand1)))]))


; problem 1f: show an example of returning a function as a result of another function


; There are only two hard things in Computer Science: cache invalidation and naming things.
(define (multiple-fun x)
  (cond
    [(number? x) (lambda(d) (* d d))]
    [(procedure? x) (lambda(d) (* d d))]
    [(atom? x) (lambda(d) (display d))]
    [else (lambda(d) (car d))]))
;  (if (number? x)
;      (lambda(d) (* d d))
;      (lambda(d) (display d))))


; problem 1g: show examples of:
;    reading function(s) from the keyboard,
;    reading function(s) from a file,
;    and displaying a function


(define (read-fun-from-keyboard)
  (eval (read)))

(define (execute-from-keyboard x)
  ((read-fun-from-keyboard) x))

