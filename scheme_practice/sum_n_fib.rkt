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


(define (sorted? num-list)
  (or (< (length num-list) 2)
      (and (<= (car num-list)
               (cadr num-list))
           (sorted? (cdr num-list)))))

(define (sorted2? seq comp)
  (or (comp (length seq) 2)
      (and (comp (car seq)
                 (cadr seq))
           (sorted2? (cdr seq) comp))))


(define (double-all ls)
  (if (empty? ls) null
      (cons (* 2 (car ls))
            (double-all (cdr ls)))))

(define (incr-all ls)
  (if (empty? ls) null
      (cons (+ 1 (car ls))
            (incr-all (cdr ls)))))

(define (generic-mod ls comp operand)
  (if (empty? ls) null
      (cons (comp operand (car ls))
            (generic-mod (cdr ls) comp operand))))

(define (double x) (* x 2))

(define (inc x) (+ x 1))

(define (my-unary-map fun ls)
  (if (empty? ls) null
      (cons (fun (car ls))
            (my-unary-map fun (cdr ls)))))

(define (average num-list)
  (/ (apply + num-list)
     (length num-list)))

(define (flatten2 seq)
  (if (not (list? seq)) (list seq)
           (apply append (map flatten2 seq))))

(define (translate points delta)
  (map (lambda (x) (+ x delta)) points))