(define s4-interpret (lambda (e)
  (cond 
    ;; If the input expression is a number, then
    ;; the value of the expression is that number.
    ((number? e) e)

    ;; Otherwise, we must see a list.
    ((not (list? e)) 
          (error "s4-interpret: cannot evaluate -->" e))

    ;; First evaluate the value of the operands
    ;; by recursive calls, and then evaluate the
    ;; the value of the entire expression.
    ((equal? '+ (car e))
          (apply + (map s4-interpret (cdr e))))

    ;; If the expression is not in a form that we can handle
    ;; then produce an error.
    (else (error "s4-interpret: cannot evaluate -->" e)))))
