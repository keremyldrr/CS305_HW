
(define negate (lambda (n) (* -1 n)))
(define multicons (lambda (n t) (cons (* n t) ())))
(define operator (lambda (n) (car (cdr n))))

(define twoOp
  (lambda (elements)

    (if (eq? (cdr elements) '())
	(car elements)
       ;else
    (if (eq? (operator elements) '-)
	(+ (car elements) (twoOp (append (cons (negate (car (cddr elements))) ()) (cdr (cddr elements))))) ;subtraction
	(+ (car elements) (twoOp (cddr elements))) ;else

	;   (+ 31 31)
	)
	
	;)
    )
  
  ) 
)

(define fourOp
  
    (if (eq? (cdr elements) '())
	(car elements)
					;else
	(if (eq? (operator elements) '*)
	    ( )
	    (if eq? (operator elements '/))()()
	    )
	
	) 
    
    )
