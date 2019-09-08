.name "MacaronFraise"
.comment "Ca rame du cul - floblanc, 2019"

meringue: sti r1, %:sucreglace, %1

sucreglace: live %0

laduree:	live %:meringue
			live %:meringue
			fork %200
			live %:meringue
			fork %3072
			zjmp %:laduree
