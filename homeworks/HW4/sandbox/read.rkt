#lang racket

(define read-demo
  (lambda ()
    (display "Enter data (enter 'done' when finished): ")
    (let ((response (read)))
      (cond
        [(eq? response 'done) (display "Thank you. Good-bye.\n")]
        [else (display "You have entered: ")
              (write response)
              (newline)
              (read-demo)]))))