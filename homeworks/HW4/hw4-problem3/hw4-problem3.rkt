#lang racket

(define (non-negative? x)
  (if (or (equal? x 0)
          (positive? x)) #t #f))

(define (valid-input? x)
  (if (and (number? x)
           (and (integer? x)
                (non-negative? x))) #t #f))

(define (line x)
  (if (not (valid-input? x)) (display "Argument must be a non-negative integer.\n")
      (if (equal? x 0) (newline)
          (begin (display "*")
                 (line (- x 1))))))

(define (histogram lst)
  (if (not (list? lst)) (display "Argument must be a list.\n")
      (if (empty? lst) (display "")
          (begin (line (car lst))
                 (histogram (cdr lst))))))

