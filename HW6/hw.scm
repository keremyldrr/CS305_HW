(define get-operator (lambda (op-symbol)
  (cond
    ((equal? op-symbol '+) +)
    ((equal? op-symbol '-) -)
    ((equal? op-symbol '*) *)
    ((equal? op-symbol '/) /)
    (else (error "cs305env: operator not implemented -->" op-symbol)))))

(define define-stmt? (lambda (e)
    (and (list? e) (equal? (car e) 'define) (symbol? (cadr e)) (= (length e) 3))))
(define if-stmt? (lambda (e)
    (and (list? e) (equal? (car e) 'if) (= (length e) 4))))
(define checkOperator ;THIS WILL BE FIXED
  (lambda (operator operands)
    (if (or (equal? operator '/) (equal? operator '-))
	(if (< (length operands) 2)
	    #f
	    #t)
	#t)  
    )
  )
(define get-value (lambda (var env)
    (cond
      ((null? env) (error "cs305env: unbound variable -->" var))
      ((equal? (caar env) var) (cdar env))
      (else (get-value var (cdr env))))))

(define extend-env (lambda (var val old-env)
      (cons (cons var val) old-env)))

(define repl (lambda (env)
  (let* (
         (dummy1 (display "cs305> "))

         (expr (read))
         (new-env (if (define-stmt? expr)
                      (extend-env (cadr expr) (cs305env (caddr expr) env) env)
                      env))

         (val (if (define-stmt? expr)
                  (cadr expr)
                  (cs305env expr env)))


         (dummy2 (display "cs305: "))
         (dummy3 (display val))


         (dummy4 (newline))
         (dummy4 (newline)))
     (repl new-env))))

(define cs305env (lambda (e env)
  (cond
    ((number? e) e)
    ((symbol? e) (get-value e env))
    ((not (list? e))
          (error "cs305env: cannot evaluate -->" e))
    ((if-stmt? e) (if (not (eq? (cs305env (cadr e) env) 0))
		      (cs305env (caddr e) env)
		      (cs305env (cadddr e) env))
     )
    (else
       (let ((operands (map cs305env (cdr e) (make-list (length (cdr e)) env)))
             (operator (get-operator (car e))))

         (if (checkOperator operator operands)
	     (apply operator operands)
	     (error "bad operators")
	     )
	 )
       )
    )
  )
  )
(define cs305 (lambda () (repl '())))
