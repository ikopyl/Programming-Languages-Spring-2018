#lang racket

(define (fread inport)
    (let ((item (read inport))
          )
      (cond
        [(eof-object? item) (display "")]
        [else (eval item)
              (fread inport)])))

(define (show file)
    (let ((inport (open-input-file file)))
      (fread inport)
      (close-input-port inport)
      (display "")))




; (show "/Users/ilya.kopyl/depot/git_home/csc600/homeworks/HW4/sandbox/function.txt")

; (show "/Users/ilya.kopyl/Documents/functions.txt")

; (define in (open-input-file "/Users/ilya.kopyl/Documents/functions.txt"))

; (close-input-port in)


(define (flatten1 seq)
  (cond
    [(empty? seq) '()]
    [(list? (car seq)) (append (flatten1 (car seq))
                               (flatten1 (cdr seq)))]
    [else (cons (car seq)
                (flatten1 (cdr seq)))]))

(define (flatten2 seq)
  (if (not (list? seq))
      (list seq)
      (apply append (map flatten2 seq))))

(define (atom? x)
  (and (not (pair? x))
       (not (null? x))))   

(define (conveyor lst-functions lst-data-operand1) (cond
[(empty? lst-functions) lst-data-operand1]
[(procedure? lst-functions) (map lst-functions lst-data-operand1)] [else (conveyor (cdr lst-functions)
(if (procedure? (car lst-functions))
(map (car lst-functions) lst-data-operand1)
(map (eval (car lst-functions)) lst-data-operand1)))]))
