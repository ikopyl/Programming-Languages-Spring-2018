#lang racket


(define (square x)
  (* x x))

(define (squarelist x)
  (map square x))

; at least 1 argument is required
(define (sqr x . y)
  (cons (square x) (squarelist y)))

(define (sqr-new x . y)
  (squarelist (cons x y)))


(define (sumlist x)
  (apply + x))

; there are no required arguments, the sum of empty list is zero
(define (sum . x)
  (sumlist x))

; at least 1 argument is required
(define (mean_old x . y)
  (/ (sum x (sumlist y))
     (+ 1 (length y))))

(define (mean lst)
  (/ (sumlist lst)
     (length lst)))



; initial version of the function that takes a list of arguments:
(define (sigma-old lst)
  (sqrt (-
         (/ (apply + (map square lst)) (length lst))
         (square (/ (apply + lst) (length lst))))))

; second attempt:
(define (sigma x . y)
  (sqrt (- (mean (sqr (sum x y)))
           (sqr (mean x y)))))



(define lst1 '(1 2 3 2 1))

(define lst2 '(1 3 1 3 1 3))

(define lst3 '(1 3))

(define lst4 '(1))

