; Exercice 1

(defun extreme-rec (v i n mn mx)
	(if (= i n) (cons mn mx)
	(let ((x (svref v i)))							;svref retourne le ieme element du vecteur
		(extreme-rec v (+ i 1) n (if (< x mn) x mn) (if (> x mx) x mx)))))

(defun extreme (v)
  (extreme-rec v 1 (length v) (svref v 0) (svref v 0)))

(extreme (vector 5 3 4 6 8 1))

; Exercice 2

(defun precede (x v)
	(let (acc (v1 (concatenate 'vector v))) ; "concatenate" prend v et le transforme en vecteur
		(dotimes (i (length v1))
			(if (and (eql x (aref v1 i)) (< 0 i)) ; aref idem que svref
				(push (aref v1 (- i 1)) acc)))
		(remove-duplicates acc)))
	
	
(defun presede (obj vec)
	(let ((res '()))
		(dotimes (i (- (length vec) 1) res)
			(if (equal obj (aref vec (+ i 1)))
				(setf res (adjoin (aref vec i) res)))))) ; "adjoin" idem que push mais supprime les duplicates

(defun pos+rec (ls i)
	(if ls
		(cons (+ i (car ls)) (pos+rec (cdr ls) (+ i 1)))))


(defun pos+ (ls)
	(pos+rec ls 0))

;; ALternative
(defun pos2+ (ls &optional (i 0)) ; we need an optional parameter
	(if ls
		(cons (+ i (car ls)) (pos2+ (cdr ls) (+ i 1)))))

;; Iterative
(defun pos3+ (ls)
	(do ((ls1 ls (cdr ls1)) (i 0 (+ i 1)) (acc nil (cons (+ i (car ls1)) acc))) ; Variables et initialisation + incr
		((not ls1) (reverse acc))))												; Conditions d'arrêts

;; Mapcar
(defun pos4+ (ls)
	(let ((i -1))
		(mapcar #'(lambda (x) (+ x (incf i))))


;; Exercice 4
(if (eql 0 (rem i 2)) 
			
		)


(defun insert(obj ls)
	(do ( (ls1 ls (cdr ls1)) (i -1 (+ i 1)) (acc nil (cons acc (car ls1))) )
		((not ls1) acc)
		(if (eql 0 (rem i 2)) 
			(setf acc (cons obj acc))
		)
	)
)