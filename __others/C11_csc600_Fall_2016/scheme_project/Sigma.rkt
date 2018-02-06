#lang racket

;QUESTION 2
(define (sumlist lst) ;Sum a list and return value
  (if (null? lst) 0 (+ (car lst) (sumlist (cdr lst)))))

(define (sumsquare lst) ;Square each element of a list and sum it
  (if (null? lst) 0 (+ (* (car lst) (car lst)) (sumsquare (cdr lst)))))

(define mean (lambda (x . y) ;Get the mean of list size 1 or more
  (/ (+ x (sumlist y)) (+ 1 (length y)))))

(define sqmean (lambda (x . y) ;Get the mean of the square of list size 1 or more
  (/ (+ x (sumsquare y)) (+ 1 (length y)))))

(define sigma (lambda (x . y) ;Calculates the sigma of a list size 1 or more 
  (sqrt (- (apply sqmean x y) (* (apply mean x y) (apply mean x y))))))

; QUESTION 3
; ( a )
(define (line x)
  (cond
    ((eqv? 0 x) (newline)) ;newline on condition
    ;else make recursive call
    (else (display "*") (line (- x 1)));finish the line
  )
)
; ( b )
(define (histogram lst)
  (cond
    ((null? lst) (newline)) ;Newline on condition
    ;else make line for head, then call line for cdr
    (else (line (car lst)) (histogram (cdr lst)))

  )
)

;QUESTION 4
(define (f x) ;Sample function
  (+ (- 0 (* x x)) (* 3 x) 5))

(define (max x1 x2)
  (cond
    ((< (- x2 x1) .0000001) ; go untill accurate to 6 digits
     ;Display the final coords of max when condition is met
     (display "(")
     (display (rationalize (/ (+ x1 x2) 2) .0000001) )
     (display ",") 
     (display (rationalize (f (/ ( + x1 x2) 2)) .0000001) )
     (display ")"))
    ;calculate new x values
    (else (let ( (new1 (+ x1 (/ (- x2 x1) 3)))
                 (new2 (- x2 (/ (- x2 x1) 3))))
            ;pick new x values and execute recursive call
            (if (< (f new1) (f new2))
                (max new1 x2)
                (max x1 new2)
            )
          )
    )
  )
)

;QUESTION 5
;Iterative version
(define (scalar-product v1 v2)
  ;Check if the vector lengths are equal
  (cond ((equal? (vector-length v1) (vector-length v2))
         (do ((i 0 (+ 1 i))
              ;Add the product of the ith place of v1 and v2
              (sum 0 (+ (* (vector-ref v1 i) (vector-ref v2 i)) sum)))
           ;sum contains the final scalar value
           ((>= i (vector-length v1)) (display sum))))
        ;in case of error in vector size
        (else (display "ERROR: Different sizes of vectors!"))
  )
)
;Recursive version
(define (recursive-scalar-product v1 v2)
  ;Check if the lengths are equal
  (cond ((equal? (vector-length v1) (vector-length v2))
         (if (= (vector-length v1) 0) 0
             ;add the product of the head of v1 and v2
             (+ (* (vector-ref v1 0) (vector-ref v2 0))
                ;add the recursive call to the rest of v1 and v2
                (recursive-scalar-product (vector-drop v1 1) (vector-drop v2 1)))
             )
         )
        ;In case of inequal lengths in v1 and v2
        (else (display "ERROR: Different sizes of vectors!"))
  )
)

;QUESTION 6

;Print out a vector
(define (printvec vec)
  (do ((i 0 (+ i 1)))
    ((>= i (vector-length vec)) (display ""))
    (display (vector-ref vec i)) (display " "))
)

;Read matrix from a file and return matching matrix
(define (read-matrix fname)
  ;open file
  (let* ((inport (open-input-file fname))
         (nrow (read inport));get row num
         (ncol (read inport));get col num
         (mat (make-vector nrow))) ;make matrix
    (do ((i 0 (+ i 1)))
      ((>= i nrow) (close-input-port inport) mat )
      (let ((row (make-vector ncol)))
        (do ((j 0 (+ j 1))) ; nested do loop to go thru matrix
          ((>= j ncol) (vector-set! mat i row))
          (vector-set! row j (read inport)) ;read each item
          )
        )
      )
    )
  )
;return ith row of matrix in file
(define (ro fname i)
  (define mat (read-matrix fname))
  (vector-ref mat i))

;display ith row of matrix in file 
(define (row fname i)
  (printvec (ro fname i)))

;return ithe col of matrix in file
(define (co fname j)
  (define mat (read-matrix fname))
  (define nrow (vector-length mat))
  (define column (make-vector nrow))
  (do ((i 0 (+ i 1)))
    ((>= i nrow) column)
    (vector-set! column i (vector-ref (vector-ref mat i) j))))

;display ith col of matrix in file
(define (col fname j)
  (printvec (co fname j)))

;( b )

;returns the dot product of v1 * v2
(define (dot-product v1 v2)
  ( do ((i 0 (+ 1 i)) (sum 0 (+ sum (* (vector-ref v1 i)
                      (vector-ref v2 i)))))
     ((>= i (vector-length v1)) sum)))

(define (mmul f1 f2 f3)
  (define m1 (read-matrix f1))
  (define m2 (read-matrix f2))
  (define nrow (vector-length m1))
  (define ncol (vector-length m2))
  (define outport (open-output-file f3))
  ;write the resulting matrix 
  (display nrow outport) (display " " outport)
  (display ncol outport) (newline outport)
  (do ((i 0 (+ 1 i)))
    ((>= i nrow) (close-output-port outport) (display ""))
    (let ((row (make-vector ncol)))
      (do ((j 0 (+ 1 j))); nested do loop
        ((>= j ncol) (printvec row) (newline) (newline outport))
        ;get dot product and write it to new file 
        (vector-set! row j (dot-product (ro f1 i) (co f2 j)))
        (display (vector-ref row j) outport) (display " " outport)))))
      