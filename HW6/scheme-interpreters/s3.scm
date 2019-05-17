(define s3-interpret (lambda (e)
  (cond 
    ;; If the input expression is a number, then
    ;; the value of the expression is that number.
    ((number? e) e)

    ;; Otherwise, we must see a list.
    ((not (list? e)) 
          (error "s3-interpret: cannot evaluate -->" e))

    ;; The length of the list must be 3.
    ((not (= (length e) 3)) 
          (error "s3-interpret: cannot evaluate -->" e))

    ;; The 1st element of the list (the operator of the
    ;; expression must be +.
    ;; If it is, first evaluate the value of the operands
    ;; by recursive calls, and then evaluate the
    ;; the value of the entire expression.
    ((equal? '+ (car e))
          (+ (s3-interpret (cadr e)) (s3-interpret (caddr e))))

    ;; If the expression is not in a form that we can handle
    ;; then produce an error.
    (else (error "s3-interpret: cannot evaluate -->" e)))))
