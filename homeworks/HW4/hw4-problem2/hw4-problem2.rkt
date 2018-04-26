#lang racket


(define (square x)
  (* x x))

; initial version of the function that takes a list of arguments:
(define (sigma lst)
  (sqrt (-
         (/ (apply + (map square lst)) (length lst))
         (square (/ (apply + lst) (length lst))))))

(define lst1 '(1 2 3 2 1))

(define lst2 '(1 3 1 3 1 3))

(define lst3 '(1 3))

(define lst4 '(1))

