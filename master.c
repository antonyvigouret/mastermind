#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "master.h"

// fonction qui initialise une solution (4 couleurs)
void initialiser_solution(int sol[]) {
   srand(time(0));
   for (int i=0; i<NB_COLONNES; i++){
       sol[i]=(rand()%NB_COULEURS)+1;
       printf("%d", sol[i]);
   }
   printf("\n");
}

// fonction qui initialise un plateau vierge
void initialiser_plateau(int plateau[][6]){
   for (int i=0; i<NB_LIGNES; i++){
       for (int j=0; j<6; j++){
           plateau[i][j]=0;
           printf("%d", plateau[i][j]);
       }
       printf("\n");
   }
}


combinaison compiler_proposition(int proposition[], int solution[]) {
	combinaison resultat;
    resultat.bienp = 0;
    resultat.malp = 0;

    int soltmp[4];
    for (int i = 0; i < 4; i++) soltmp[i] = solution[i];

    for (int i=0; i<NB_COLONNES; i++){
        if (proposition[i] == soltmp[i]){
             resultat.bienp++;
             soltmp[i] = 0;
        }else {
            for (int j=0; j<NB_COLONNES; j++){
                if (proposition[i] == soltmp[j]) {
                    resultat.malp++;
                    break;
                }
            }
        }
    }
    return resultat;
} 