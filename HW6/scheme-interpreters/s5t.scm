(define s5-interpret (lambda (e)
  (cond 
    ;; If the input expression is a number, then
    ;; the value of the expression is that number.
    ((number? e) e)

    ;; Otherwise, we must see a list.
    ((not (list? e)) 
          (error "s5-interpret: cannot evaluate -->" e))

    ;; First evaluate the value of the operands
    ;; by recursive calls, and then evaluate the
    ;; the value of the entire expression.

    ;; If the operator is addition, then apply +
    ((equal? '+ (car e))
          (apply + (map s5-interpret (cdr e))))

    ;; If the operator is subtraction, then apply -
    ((equal? '- (car e))
          (apply - (map s5-interpret (cdr e))))

    ;; If the operator is multiplication, then apply *
    ((equal? '* (car e))
          (apply * (map s5-interpret (cdr e))))

    ;; If the operator is division, then apply /
    ((equal? '/ (car e))
          (apply / (map s5-interpret (cdr e))))

    ;; If the expression is not in a form that we can handle
    ;; then produce an error.
    (else (error "s5-interpret: cannot evaluate -->" e)))))
