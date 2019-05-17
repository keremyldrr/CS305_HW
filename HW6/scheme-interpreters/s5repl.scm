(define get-operator (lambda (op-symbol) 
  (cond 
    ((equal? op-symbol '+) +)
    ((equal? op-symbol '-) -)
    ((equal? op-symbol '*) *)
    ((equal? op-symbol '/) /)
    (else (error "s5-interpret: operator not implemented -->" op-symbol)))))

(define repl (lambda ()
  (let* (
         ; first print out some prompt
         (dummy1 (display "cs305> "))

         ; READ an expression
         (expr (read))

         ; EVALuate the expression read
         (val (s5-interpret expr))

         ; PRINT the value evaluated together
         ; with a prompt as MIT interpreter does
         (dummy2 (display "cs305: "))
         (dummy3 (display val))

         ; get ready for the next prompt
         (dummy4 (newline))
         (dummy4 (newline)))
     (repl))))

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

