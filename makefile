Objects = main.o FCFS.o RR.o SPF.o SRT.o Fonctions.o Avec_priorite.o Priorite.o   
cc = gcc

all : main.o FCFS.o RR.o SPF.o SRT.o Fonctions.o Avec_priorite.o Priorite.o output clean execute

main.o      	: main.cpp structures.h Fonctions.h FCFS.h SRT.h SPF.h Priorite.h RR.h Avec_priorite.h
	        		$(cc) -c main.cpp
FCFS.o      	: FCFS.cpp structures.h Fonctions.h
	 				$(cc) -c FCFS.cpp
RR.o        	: RR.cpp structures.h Fonctions.h
	 				$(cc) -c RR.cpp
SPF.o  	    	: SPF.cpp structures.h Fonctions.h
	 				$(cc) -c SPF.cpp
SRT.o  	    	: SRT.cpp structures.h Fonctions.h
	 				$(cc) -c SRT.cpp
Fonctions.o 	: Fonctions.cpp structures.h
					$(cc) -c Fonctions.cpp
Avec_priorite.o : Avec_priorite.cpp structures.h Fonctions.h
					$(cc) -c Avec_priorite.cpp
Priorite.o		: Priorite.cpp structures.h Fonctions.h
					$(cc) -c Priorite.cpp
output 			:   $(Objects)
					$(cc) $(Objects) -o $(out)
clean			: 
					rm -f *.o
execute 		: 
					./$(out)	
