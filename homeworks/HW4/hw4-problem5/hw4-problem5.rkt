#lang racket

; the inner product of two vectors:
; A * B = (a1 * b1 + a2 * b2 + ... + an * bn)

; auxiliary predicate
(define (both-vectors? v1 v2)
  (if (and (vector? v1) (vector? v2)) #t #f))

; auxiliary predicate
(define (vector-lengths-equal? v1 v2)
  (if (equal? (vector-length v1) (vector-length v2)) #t #f))

; auxiliary predicate
(define (valid-vectors-input? v1 v2)
  (if (not (both-vectors? v1 v2))
      (display "Error: Both arguments must be vectors.\n")
      (if (not (vector-lengths-equal? v1 v2))
          (begin (display "Error: Both vectors must have the same length.\n") #f)
          #t)))

; main program - entry point
(define (inner-product v1 v2 is-recursive)
  (if (not (valid-vectors-input? v1 v2)) (display "")
      (if (equal? is-recursive #t)
          (inner-product-recursive (vector->list v1) (vector->list v2))
          (inner-product-iterative v1 v2))))

; recursive implementation of inner-product
(define (inner-product-recursive lst1 lst2)
  (cond
    [(empty? lst1) 0]
    [(+ (* (car lst1) (car lst2)) (inner-product-recursive (cdr lst1) (cdr lst2)))]))
  
; iterative implementation of inner-product
(define (inner-product-iterative v1 v2)
  (let ((sum 0))
    (do ((i 0 (add1 i)))
      ((>= i (vector-length v1)) (display sum))
      (set! sum (+ sum (* (vector-ref v1 i) (vector-ref v2 i)))))))
   
        