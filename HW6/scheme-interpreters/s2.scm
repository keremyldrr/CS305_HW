(define s2-interpret (lambda (e)
  (cond 
    ;; If the input expression is a number, then
    ;; the value of the expression is that number.
    ((number? e) e)

    ;; Otherwise, we must see a list.
    ((not (list? e)) 
          (error "s2-interpret: cannot evaluate -->" e))

    ;; The length of the list must be 3.
    ((not (= (length e) 3)) 
          (error "s2-interpret: cannot evaluate -->" e))

    ;; The 2nd element of the list (1st operand of the 
    ;; expresion)) must be a number.
    ((not (number? (cadr e)))
          (error "s2-interpret: cannot evaluate -->" e))

    ;; The 3rd element of the list (2nd operand of the 
    ;; expression) must be a number.
    ((not (number? (caddr e)))
          (error "s2-interpret: cannot evaluate -->" e))

    ;; The 1st element of the list (the operator of the
    ;; expression must be +.
    ;; If it is, evaluate the value of the expression.
    ((equal? '+ (car e))
          (+ (cadr e) (caddr e)))

    ;; The expression is not in a form that we can handle.
    ;; Produce an error.
    (else (error "s2-interpret: cannot evaluate -->" e)))))
