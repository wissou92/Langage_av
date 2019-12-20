;; Exercice 1
(defun n-av (&rest av)
	(length av))
	
	
(apply #'+ 3 4) (+ 3 4)
	
;; Exercice 2
(defun max_arg (&rest av)
	(apply #'max av))
	
;; Exercice 3

(let (mx)
	(defun max-appel(nb)
		(if(and mx (> nb mx))
			(progn
				(setf mx nb)
				t)
			(progn
				(setf mx nb)
				nil)
		)
	)
)

;; Exercice 4

(defun lines->list(file)
	(with-open-file (str file :direction :input)
		(do ((line (read-line str nil nil) (read-line str nil nil)) (acc nil (cons line acc)))
			((not line) (nreverse acc))
		)
	)
)

;; Exercice 5

(defun remove-comments (fin fout &optional (cchar #\%))
	(with-open-file (s-in fin :direction :input)
		(with-open-file (s-out fout :direction :output)
			(do ((line (read-line s-in nil nil) (read-line s-in nil nil)))
				((not line))
				(let ((cp (position cchar line)))
					(format s-out "~A~%"
						(if cp (subseq line 0 cp) line)))))))
