#lang racket

(define (square x)
  (* x x))

(define (squarelist x)
  (map square x))

; at least 1 argument is required
(define (sqr x . y)
  (squarelist (cons x y)))


(define (sumlist x)
  (apply + x))

; there are no required arguments, the sum of empty list is zero
(define (sum . x)
  (sumlist x))


; at least 1 argument is required
(define (mean x . y)
  (/ (sum x (sumlist y))
     (+ 1 (length y))))

(define (meanlist lst)
  (/ (sumlist lst)
     (length lst)))


; second attempt:
(define (sigma-old x . y)
  (sqrt (- (meanlist (squarelist (cons x y)))
           (square (meanlist (cons x y))))))

; let's introduce a local scope:
(define (sigma x . y)
  (let ((mydata (cons x y)))
    (sqrt (- (meanlist (squarelist mydata))
             (square (meanlist mydata))))))




(define lst1 '(1 2 3 2 1))

(define lst2 '(1 3 1 3 1 3))

(define lst3 '(1 3))

(define lst4 '(1))

