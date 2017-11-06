#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teZZt.h"
#include "master.h"

/*
   - decommenter au fur et a mesure que vous suivez l enonce et que le code est ecrit
   - compiler avec gcc *.c -g -Wall -Wextra -o executable
*/


BEGIN_TEST_GROUP(master)

TEST(initialisation_solutions) {
   int i, j;
   int solution[NB_COLONNES];
   
   for (i = 0; i < 100; ++i) {
      initialiser_solution(solution);
      for (j = 0; j < NB_COLONNES; ++j) {
         CHECK(solution[j] > 0);
         CHECK(solution[j] <= NB_COULEURS);
      }
   }
}

TEST(initialisation_plateau) {
   int i, j;
   int plateau[NB_LIGNES][NB_COLONNES];

   initialiser_plateau(plateau);
   // initialiser_plateau(plateau, NB_LIGNES, NB_COLONNES);

   for (i=0; i < NB_LIGNES; ++i)
      for (j=0; j < NB_COLONNES; ++j)
         CHECK( 0 == plateau[i][j] )
}

TEST(combinaison1) {
   int solution = {1, 1, 1, 1};
   int proposition[NB_COLONNES] = { 2, 2, 2, 2};
   combinaison c;
 
   c = compiler_proposition(proposition, solution);
   REQUIRE( 0 == c.bienp );
   REQUIRE( 0 == c.malp );

   proposition[1] = 1;
   c = compiler_proposition(proposition, solution);
   REQUIRE( 1 == c.bienp );
   REQUIRE( 0 == c.malp );   

   proposition[2] = 1;
   c = compiler_proposition(proposition, solution);
   REQUIRE( 2 == c.bienp );
   REQUIRE( 0 == c.malp );

   proposition[3] = 1;
   c = compiler_proposition(proposition, solution);
   REQUIRE( 3 == c.bienp );
   REQUIRE( 0 == c.malp );

   proposition[0] = 1;
   c = compiler_proposition(proposition, solution);
   REQUIRE( 4 == c.bienp );
   REQUIRE( 0 == c.malp );
}

TEST(combinaison2) {
   int solution = {3, 3, 1, 2};
   int proposition[NB_COLONNES] = { 4, 4, 4, 4};
   combinaison c;
 
   c = compiler_proposition(proposition, solution);
   REQUIRE( 0 == c.bienp );
   REQUIRE( 0 == c.malp  );

   proposition[0] = proposition[1] = proposition[2] = proposition[3] = 1;
   c = compiler_proposition(proposition, solution);
   REQUIRE( 1 == c.bienp );
   REQUIRE( 0 == c.malp  );   

   proposition[0] = proposition[1] = 5;
   proposition[2] = proposition[3] = 3;
   c = compiler_proposition(proposition, solution);
   REQUIRE( 0 == c.bienp );
   REQUIRE( 2 == c.malp  );

   proposition[0] = 2; proposition[1] = 1;
   proposition[2] = proposition[3] = 3;
   c = compiler_proposition(proposition, solution);
   REQUIRE( 0 == c.bienp );
   REQUIRE( 4 == c.malp  );

   proposition[0] = proposition[1] = 3;
   proposition[2] = 2; proposition[3] = 1;
   c = compiler_proposition(proposition, solution);
   REQUIRE( 2 == c.bienp );
   REQUIRE( 2 == c.malp  );

   proposition[0] = proposition[1] = 3;
   proposition[2] = 1; proposition[3] = 2;
   c = compiler_proposition(proposition, solution);
   REQUIRE( 4 == c.bienp );
   REQUIRE( 0 == c.malp  );
}


END_TEST_GROUP(master)


int main(void) {
	RUN_TEST_GROUP(master); 
 	return 0;
}
