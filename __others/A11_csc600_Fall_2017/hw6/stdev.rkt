#|;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
HW6/2 stdev.rkt created by Nao F. (Nov 21, 2014)
calculates the standard deviation sigma from the given number(s)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;|#
#lang racket
(define (square x) (* x x))
(define (sumlist lst)
  (if (null? lst) 0 (+ (car lst) (sumlist (cdr lst)))))
(define (sqsumlist lst)
  (if (null? lst) 0 (+ (square (car lst)) (sqsumlist (cdr lst)))))
(define sigma (lambda x (sqrt (- (/ (sqsumlist x) (length x))
                                 (square (/ (sumlist x) (length x)))))))