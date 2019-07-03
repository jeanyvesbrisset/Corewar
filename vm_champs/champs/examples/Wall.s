.name "Wall"
.comment "Werror(you) Wextra(me)"

start: ld		%1, r14
	zjmp	%:wallstart
	st		r15, -8				#	15
	
stlive: sti	    r1,	%:wall,	%1		#	7
	sti		r1, %:alive, %1
	sti		r1, %:forklive, %1
	sti		r1, %:wallstart, %1
	sti		r1, %:forke, %1
	sti     r1, %:forke, %9
	sti     r1, %:kta, %1
	sti     r1, %:kta, %9
	sti     r1, %:kta, %17		#	63
								#	78
forke: live	%66
	fork	%:wallstart
	live	%66
	fork	%:forke				#	16
								#	94
kta: live	%2576980377			#	99
	lfork	%925
	live    %66					#	107
	lfork   %1941
	live    %66					#	115
	lfork   %2957
	
forklive:	live	%66
	fork	%:forklive

alive: live	%66
	ld		%0, r16
	zjmp	%:alive

wallstart: live	%66
    ld      %42991616, r2
	ld      %265, r3
	ld      %4294508544, r4
	fork	%:wallstart

wall:
	live    %66
	st      r2, -300
	ld		%0, r16
	zjmp	%:wall
