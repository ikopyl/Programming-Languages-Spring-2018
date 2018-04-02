#lang racket

(define (sum ls)
  (if (null? ls) 0
      (+ (car ls) (sum (cdr ls)))))

(define (fib n)
  (if (<= n 1) n
      (+ (fib (- n 1)) (fib (- n 2)))))

