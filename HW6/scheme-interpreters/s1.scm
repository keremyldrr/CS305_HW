(define s1-interpret (lambda (e)
  (cond
    ;; If the input expression is a number, then 
    ;; the value of the expression is that number.
    ((number? e) e)

    ;; If the expression is not a number then,
    ;; we cannot handle it. Produce an error.
    (else (error "s1-interpret: cannot evaluate -->" e)))))
