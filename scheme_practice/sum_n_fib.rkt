#lang racket

(define (sum ls)
  (if (null? ls) 0
      (+ (car ls)
         (sum (cdr ls)))))

(define (fib n)
  (if (<= n 1) n
      (+ (fib (- n 1))
         (fib (- n 2)))))

;; checkout racket/collects/racket/list.rkt
(define (flatten1 sequence)
    (cond 
           [(empty? sequence) null]
           
           [(list? (car sequence))
            (append (flatten1 (car sequence))
                    (flatten1 (cdr sequence)))]
           
           [else (cons (car sequence)
                       (flatten1 (cdr sequence)))]
           
           )
  )