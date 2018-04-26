#lang racket

(define (square x)
  (* x x))

(define (square-lst x)
  (map square x))


(define (sum-lst x)
  (apply + x))


(define (mean-lst lst)
  (/ (sum-lst lst)
     (length lst)))


; at least 1 argument is required
(define (sigma x . y)
  (let ((data (cons x y)))
    (sqrt (- (mean-lst (square-lst data))
             (square (mean-lst data))))))




(define lst1 '(1 2 3 2 1))

(define lst2 '(1 3 1 3 1 3))

(define lst3 '(1 3))

(define lst4 '(1))

