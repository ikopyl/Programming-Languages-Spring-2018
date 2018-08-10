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


; (define grades '(100 94 92 88 87 87 86 82 82 80 80 76 75 75 73 73 73 72 72 71 71 70 70 70 69 69 69 68 68 67 67 67 65 64 63 63 62 61 61 59 58 58 57 56 56 56 56 56 54 53 48 46 46 46 45 45 45 45 45 44 44 42 42 41 40 40 40 39 39 38 38 37 37 36 35 34 34 34 33 32 31 30 28 27 26 25 24 24 22 22 22 21 21 20 19 19 18 18 18 18 18 16 16 16 15 13 13 13 12 10 8 4))

; csc415 preliminary grades (after assignment 4)
(define grades '(75.31 97.28 94.42 98.24 80.04 100.8 86.54 88.75 87.95 84.64 92.88 87.59 72.66 93.04 72.52 86.38 90.11 76.25 97.75 95.92 71.9 78.15 92.79 88.1 81.12 79.17 88.57 84.46 89.69 80.56 99.69 74.62 69.06 87.01 78.84 87.99 95.4 46.81 92.23 95.25 103.9 ))

(define final_grades '(85.0 97.7 94.2 99.4 31.9 96.2 92.8 90.3 91.6 87 90.3 81.5 82.7 95.7 79.2 86.4 83.1 81.2 94.4 97.6 81.3 92.6 95.5 88.6 85.4 87.7 90.8 89.2 90.0 82.5 98.7 82.6 76.0 86.5 82.6 88.4 100.0 73.8 96.5 94.5 102.0))

(define final_exam_grade '(52 59 61 63 0 53 58 53 54 51 55 51 61 60 51 46 52 50 54 55 47 63 58 55 53 55 54 52 54 52 57 47 50 57 50 51 63 53 58 53 60))

(define p5_grade '(165 175 165 175 25 165 150 175 175 165 150 140 155 175 150 155 100 165 160 175 170 155 175 115 175 175 175 175 155 165 175 175 125 170 155 150 175 175 175 170 175))

(define (variance-lst lst)
  (- (mean-lst (square-lst lst))
     (square (mean-lst lst))))

; standard deviation
(define (sigma-lst lst)
  (sqrt (variance-lst lst)))

; The coefficient of variance
(define (varco-lst lst)
  (/ (sigma-lst lst) (mean-lst lst)))



