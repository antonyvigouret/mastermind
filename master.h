#ifndef master_h
#define master_h

/* DECLARATION DES CONSTANTES SYMBOLIQUES */

#define NB_COLONNES 4
#define NB_LIGNES 10
#define NB_COULEURS 4


/* DECLARATION DES TYPES PERSONNELS */
// et de leur typedef si besoin

typedef struct {
    int bienp;
    int malp;
} combinaison;

/* DECLARATIONS DES METHODES */

void initialiser_solution(int sol[]);
void initialiser_plateau(int plateau[][6]);
combinaison compiler_proposition(int proposition[], int solution[]);
void actualiser_plateau(int plateau[][6], int proposition[],int solution[], int tour);
void saisir_proposition(int proposition[]);
int compare(int proposition[], int solution[]);
void viderBuffer();
// mettre ici les autres declarations

#endif