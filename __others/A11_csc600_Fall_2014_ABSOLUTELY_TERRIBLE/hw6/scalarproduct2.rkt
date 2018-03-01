#|;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
HW6/5(b) scalarproduct2.rkt created by Nao F. (Nov 21, 2014)
calculates the scalar product of the given 2 vectors using recursion
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
           (splist (vector->list v1) (vector->list v2)))
          (else (display "Error: different sizes of vectors!")))))
(define splist
    (lambda (list1 list2)
      (cond ((null? (cdr list1)) (* (car list1) (car list2)))
            (else (+ (* (car list1) (car list2))
                     (splist (cdr list1) (cdr list2)))))))
