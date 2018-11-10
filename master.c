#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "master.h"

// fonction qui initialise une solution (4 couleurs)
void initialiser_solution() {
   srand(time(0));
   int sol[4];
   for (int i=0; i<4; i++){
       sol[i]=(rand()%4)+1;
       printf("%d", sol[i]);
   }
}

// un petit commentaire ?
void initialiser_plateau(){
   // TO DO
}

/*
 compiler_proposition() {
	
} */