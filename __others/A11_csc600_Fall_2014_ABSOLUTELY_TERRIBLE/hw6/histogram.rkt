#|;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
HW6/3 histogram.rkt created by Nao F. (Nov 21, 2014)
(a)prints n asterisk(s) in a line
(b)prints a histogram using a recursive procedure and the line in (a)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;|#
#lang racket
(define (line n)
  (cond ((< n 1) (newline))
        (else (display "*") (line (- n 1)))))
(define (histogram lst)
  (if (null? lst) (newline)
      (begin (line (car lst))
             (histogram (cdr lst)))))