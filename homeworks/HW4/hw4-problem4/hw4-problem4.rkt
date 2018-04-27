#lang racket

; The trisection method for finding the maximum of f(x) within the
; interval [x1, x2] starts by dividing the interval in three equal
; segments using the middle points a1 = x1 + (x2 - x1)/3, and a2 =
; x2 - (x2 - x1)/3. If f(a1) < f(a2) then a1 becomes the new value
; of x1; otherwise a2 becomes the new value of x2. Each such a step
; reduces the size of the [x1, x2] interval and this process terminates
; when the interval becomes sufficiently small. Then the coordinate
; of the maximum is xmax = (x1+x2)/2, yielding fmax = f(xmax).

; auxiliary predicate
(define (difference-sufficiently-small? x1 x2)
  (let ((threshold 1e-6))
    (if (< (abs (- x2 x1)) threshold) #t #f)))

(define (disp x n)
  (display (/ (round (* x (expt 10 n)))
              (expt 10 n))))

; auxiliary function
(define (mean x . y)
  (/ (apply + (cons x y))
     (+ 1 (length y))))

(define (fmax f x1 x2)
  (cond
    [(difference-sufficiently-small? x1 x2) (display "maximum: f(")
                                            (disp (mean x1 x2) 4)
                                            (display ") = ")
                                            (disp (f (mean x1 x2)) 4)]
    [else (let ((a1 (+ x1 (/ (- x2 x1) 3)))
                (a2 (- x2 (/ (- x2 x1) 3))))
            (if (< (f a1) (f a2))
                (fmax f a1 x2)
                (fmax f x1 a2)))]))


; (fmax (lambda(x) (* x (- 1 x))) 0 10)

; (fmax (lambda(x) (* x (- x 1))) 0 10)


