#lang racket

(define (sum ls)
  (if (null? ls) 0
      (+ (car ls) (sum (cdr ls)))))

(define (fib n)
  (if (<= n 1) n
      (+ (fib (- n 1)) (fib (- n 2)))))

(define c 0)
(define (fib2 n c s)
  (if (<= n 1) n
      (if (n <= c) (let c (sum c 1))
      