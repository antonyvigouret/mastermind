#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "master.h"




int main(){
    int sol[NB_COLONNES];
    int plateau[NB_LIGNES][6];

    initialiser_solution(sol);
    initialiser_plateau(plateau);

    int proposition[] = {1, 2, 3, 4};
    for (int i = 0; i < NB_COLONNES; i++) printf("%d ", proposition[i]);

    combinaison c=compiler_proposition(proposition, sol);
    printf("bien place : %d  mal place : %d\n", c.bienp, c.malp);


    return 0;
}