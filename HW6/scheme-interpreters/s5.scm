(define get-operator (lambda (op-symbol) 
  (cond 
    ((equal? op-symbol '+) +)
    ((equal? op-symbol '-) -)
    ((equal? op-symbol '*) *)
    ((equal? op-symbol '/) /)
    (else (error "s5-interpret: operator not implemented -->" op-symbol)))))

(define s5-interpret (lambda (e)
  (cond 
    ;; If the input expression is a number, then
    ;; the value of the expression is that number.
    ((number? e) e)

    ;; Otherwise, we must see a list.
    ((not (list? e)) 
          (error "s5-interpret: cannot evaluate -->" e))

    ;; First evaluate the value of the operands
    ;; and the procedure of the expression.
    (else 
       (let ((operands (map s5-interpret (cdr e)))
             (operator (get-operator (car e))))

         ;; And finally apply the operator to the 
         ;; values of the operands
         (apply operator operands))))))
