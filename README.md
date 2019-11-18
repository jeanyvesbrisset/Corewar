__Projet Corewar__:

Core War is a 1984 programming game created by D. G. Jones and A. K. Dewdney in which two or more battle programs (called "warriors") compete for control of a virtual computer. These battle programs are written in an abstract assembly language called Redcode.
At the beginning of a game, each battle program is loaded into memory at a random location, after which each program executes one instruction in turn. The goal of the game is to cause the processes of opposing programs to terminate (which happens if they execute an invalid instruction), leaving the victorious program in sole possession of the machine.

__Usage asm__: ./asm <sourcefile.s>

__Usage corewar__: ./corewar (-v -vb -d/-dump N) [[-n N] <champion1.cor>] <...>
	-v		: visualisation
	-vb		: show which process is use when operation are done
	-d/-dump N	: Dumps memory after N(int >= 0) cycles then exit the program
	-n N		: Give to champion(s) N(int > 0) player number

This project can be broken down into three distinctive parts:

__The assembler__: this is the program that will compile champions and translate them from the language written them in (assembly language) into “Bytecode”. Bytecode is a machine code, which will be directly interpreted by the virtual machine.  
__The virtual machine__: It’s the “arena” in which champions will be executed. It offers various functions, all of which will be useful for the battle of the champions. Obviously, the virtual machine should allow for numerous simultaneous processes.  
__The champion__: It's necessary to create a simple champion just to prove the program functionality.  
  
__How to run__:
make
./asm <sourcefile.s>
./corewar [-v | -d/-dump N] [-a] [-n N] <champion1.cor> <...>
-v : Enables visualization
-vb : show which process is use when operation are done
-dump N : Dumps memory after N cycles
-n N : Assigns id N to the player specified right after N

__Visualization__
Visualization is enabled using library. The native shell (for example, Terminal.app for macos) could show higher permormance than the third-party applications like iTerm. Colors may vary depend on your shell application settings.
