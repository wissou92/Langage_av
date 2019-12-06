// POUR CHARGER UN FICHIER LISP :
// (load "*.lsp")


// Exercice 1
(defun suc (ls)
  (let ((o (car ls)))
	     (dolist (x (cdr ls) t)
	       (if (= 1 (abs (- o x)))
		   (setf o x)
		 (return-from suc nil)))))


(defun suc2 (ls)
	   (do ((ls1 (cdr ls) (cdr ls1)) (o (car ls) (car ls1)))
	       ((not ls1) t)
	     (if (/= 1 (abs (- o (car ls1))))
		 (return nil))))

// Exercice 2

(defun sq (x)
	   (if (and (< 0 x 6) (integerp x))
	       x
	       (* x x)))

// Exercice 3

(defun mystery (x y)
  (cond
    ((null y) nil)
    ((eql (car y) x) 0)
    (t (let ((z (mystery x (cdr y)))) (and z (+ z 1))))))


// Exercice 4

(defun min-max (lst)
  (cons (apply #'min lst) (apply #'max lst)))

// Exercice 5

(defun produce (lst)
  (let ( (maxx (apply #'max lst)) )
    (*  maxx (apply #'max (remove maxx lst)))
    )
  )


// Exercice 6

(defun our-reverse (lst)
  (let ((ace nil))
    (dolist (elt lst)
      (push elt ace))
    ace)
  )


// Exercice 7

(defun our-equal (x y)
  (cond
    ((numberp x) (numberp y) (eql x y))
    ((symbolp x) (symbolp y) (eq x y))
    ((and (listp x) (listp y) (not (null x)) (not(null y)))
         (and (our-equal (car x) (car y)) (our-equal (cdr x) (cdr y))))
    (t nil)
   )
)
    
