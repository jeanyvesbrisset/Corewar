.name "lolilol"
.comment "laughing out loud xD"

l2:		add r1, r2, r2
		and r1, %0, r1

live:	live %1
		zjmp %:live
