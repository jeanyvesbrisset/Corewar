.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		zjmp %17
		and r1, %0, r1

live:	live %1
		zjmp %:live
