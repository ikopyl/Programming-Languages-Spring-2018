#lang racket

; the inner product of two vectors:
; A * B = (a1 * b1 + a2 * b2 + ... + an * bn)

; auxiliary predicate
(define (both-vectors? v1 v2)
  (and (vector? v1) (vector? v2)))

; auxiliary predicate
(define (vector-lengths-equal? v1 v2)
  (equal? (vector-length v1) (vector-length v2)))

; auxiliary predicate
(define (valid-vectors-input? v1 v2)
  (cond
    [(not (both-vectors? v1 v2))
     (begin (display "Error: Both arguments must be vectors.\n") #f)]
    [(not (vector-lengths-equal? v1 v2))
     (begin (display "Error: Both vectors must have the same length.\n") #f)]
    [else #t]))

; main program - entry point
(define (inner-product v1 v2 is-recursive)
  (cond
    [(not (valid-vectors-input? v1 v2)) (display "")]
    [else (if (equal? is-recursive #t)
              (inner-product-recursive (vector->list v1) (vector->list v2))
              (inner-product-iterative v1 v2))]))

; recursive implementation of inner-product
(define (inner-product-recursive lst1 lst2)
  (cond
    [(empty? lst1) 0]
    [(+ (* (car lst1) (car lst2))
        (inner-product-recursive (cdr lst1) (cdr lst2)))]))
  
; iterative implementation of inner-product
(define (inner-product-iterative v1 v2)
  (let ((sum 0))
    (do ((i 0 (add1 i)))
      ((>= i (vector-length v1)) sum)
      (set! sum (+ sum (* (vector-ref v1 i) (vector-ref v2 i)))))))
   
        