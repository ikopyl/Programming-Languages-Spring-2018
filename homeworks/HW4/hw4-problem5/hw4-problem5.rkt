#lang racket


; goals:

; understand what the vectors are

; understand how the inner product of two vectors works:
; A * B = (a1 * b1 + a2 * b2 + ... + an * bn)

; understand how to use the DO loop


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

; main function
(define (inner-product-rec v1 v2)
  (if (not (valid-vectors-input? v1 v2)) (display "")
           (begin (display v1)
                  (newline)
                  (display v2))))

  