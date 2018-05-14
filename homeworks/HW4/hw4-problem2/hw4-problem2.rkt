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

(define (variance x . y)
  (let ((data (cons x y)))
    (- (mean-lst (square-lst data))
             (square (mean-lst data)))))


(define lst1 '(1 2 3 2 1))

(define lst2 '(1 3 1 3 1 3))

(define lst3 '(1 3))

(define lst4 '(1))


; grades: MT Spring 2018

; 100 94 92 88 87 87 86 82 82 80 80 76 75 75 73 73 73 72 72 71 71 70 70 70 69 69 69 68 68 67 67 67 65 64 63 63 62 61 61 59 58 58 57 56 56 56 56 56 54 53 48 46 46 46 45 45 45 45 45 44 44 42 42 41 40 40 40 39 39 38 38 37 37 36 35 34 34 34 33 32 31 30 28 27 26 25 24 24 22 22 22 21 21 20 19 19 18 18 18 18 18 16 16 16 15 13 13 13 12 10 8 4

; (define (variance-lst lst)
;   (begin
;     (display (square-lst lst))
;     (newline)
;     (display (mean-lst lst))
;     (newline)
;     (display (mean-lst lst))
;     (newline)
;     (display (square (mean-lst lst)))
;     (newline)
;     (display (- (mean-lst (square-lst lst))
;                 (square (mean-lst lst))))
;     (newline)
;     (newline)
;       (- (mean-lst (square-lst lst))
;       (square (mean-lst lst)))))


; (define (sigma-lst lst)
;  (let ((variance (variance-lst lst)))
;    (sqrt variance)))

(define (variance-lst lst)
  (- (mean-lst (square-lst lst))
     (square (mean-lst lst))))

(define (sigma-lst lst)
  (sqrt (variance-lst lst)))



