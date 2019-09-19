# COREWAR

Projet Corewar pour 42:

Corewar est un projet utilisant 2 programmes differents.
Le premier, l'asm, compilera un champion em pseudo assembleur en binaire,
tandis que la vm(corewar) executera le code en binaire contre un autre champion lui aussi en binaire.

Usage: ./asm <sourcefile.s>

Usage: ./corewar (-v -vb -d/-dump N) [[-n N] <champion1.cor>] <...>
	-v		: visualisation
	-vb		: show which process is use when operation are done
	-d/-dump N	: Dumps memory after N(int >= 0) cycles then exit the program
	-n N		: Give to champion(s) N(int > 0) player number
