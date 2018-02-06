#|;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
HW6/5(a) scalarproduct1.rkt created by Nao F. (Nov 21, 2014)
calculates the scalar product of the given 2 vectors using a do loop
produces an error message when the vectors have different lengths or is empty
NOTE:racket does not have the relational operator <> 
I have made some adjustments to make the code work without it
but the code is not very pretty
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;|#
#lang racket
(define scalar-product 
  (lambda (v1 v2)
    (cond ((zero? (vector-length v1))
           (display "Error: empty vector for v1!"))
          ((zero? (vector-length v2))
           (display "Error: empty vector for v2!"))
          ((= (vector-length v1) (vector-length v2))
           (let ((s 0))
                  (do ((i 0 (add1 i)))
                    ((>= i (vector-length v1)) (display s))
                    (set! s
                          (+ s (* (vector-ref v1 i) (vector-ref v2 i)))))))
          (else (display "Error: different sizes of vectors!")))))
