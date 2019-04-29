
(define negate (lambda (n) (* -1 n)))
(define multicons (lambda (n t) (cons (* n t) ())))
(define divcons (lambda (n t) (if (eq? t 0) (error "division by zero") (cons (/ n t) ()))))
(define operator (lambda (n) (car (cdr n))))
(define listify (lambda (n) (cons n ())))
(define twoOp
  (lambda (elements)

    (if (eq? (cdr elements) '())
	(car elements)
       ;else
    (if (eq? (operator elements) '-)
	(+ (car elements) (twoOp (append (cons (negate (car (cddr elements))) ()) (cdr (cddr elements))))) ;subtraction
	(+ (car elements) (twoOp (cddr elements))) ;else

	)
    )
    ) 
  )

(define fourOp
  (lambda (elements)
    (if (eq? (cdr elements) '())
	(listify (car elements))
					;else
	(if (eq? (operator elements) '*)
	    (fourop (append (multicons (car elements) (car (cddr elements))) (cdddr elements)))

	    (if (eq? (operator elements) '/)
		(fourop (append (divcons (car elements) (car (cddr elements))) (cdddr elements)))
		;else
		(append (append  (cons (car elements) ()) (cons (car (cdr elements)) ())) (fourop (cddr elements))))
	    )
	
	) 
    
    )
  )



(define calcNested
  (lambda (elements)
    (if (eq? (cdr elements) '())
	(listify (car elements))
	(if (list? elements)
	    (calcnested (append (listify (twoOp (fourOp (car elements)))) (cdr elements)))
	    (if (list? (car elements))
		(calcnested (append (listify (twoOp (fourOp (car elements)))) (cdr elements)))
		(append (append  (cons (car elements) ()) (cons (car (cdr elements)) ())) (calcNested (cddr elements)))
		
		)
	    )
	)
    
    )
  )
