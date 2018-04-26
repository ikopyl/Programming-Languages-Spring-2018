#lang racket

(define fread
  (lambda (inport)
    (let ((item (read inport)))
      (cond
        [(eof-object? item) (display "")]
        [else (display " ")
              (display item)
              (fread inport)]))))

(define show
  (lambda (file)
    (let ((inport (open-input-file file)))
      (fread inport)
      (close-input-port inport)
      (display ""))))


