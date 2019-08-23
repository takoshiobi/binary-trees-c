#define ARBREBINAIRE

#define FILSEXISTANT 1 
#define BADARGUMENT 2
#define ARBREVIDE 3

typedef signed long int value_t ;
typedef struct NoeudBinaire_m * Noeud_t ;


struct NoeudBinaire_m 
{
	value_t  val ;
	Noeud_t  filsgauche ;
	Noeud_t  filsdroit ;
} ;


/* cr\'ee un arbre vide */
Noeud_t CreerArbreVide(void) ;

/* cr\'ee une feuille avec une valeur associ\'ee */
Noeud_t CreerNoeud(value_t) ;

/* pr\'edicat de test qu'un noeud est vide */
int EstVide (Noeud_t);

/* pr\'edicat de test qu'un noeud est une feuille.  

   CU: le noeud ne doit pas être vide, sinon produit une erreur. */
int EstFeuille (Noeud_t);

/* retourne la valeur associ\'e au noeud pass\'e en param\`etre.

   CU: le noeud ne doit pas \^etre vide */
value_t ValeurDuNoeud(Noeud_t) ;

/* ajoute en fils gauche au noeud premier argument le noeud second
   argument.

   CU: le fils gauche doit \^etre vide, sinon produit une erreur
*/
void AjouterFilsGauche(Noeud_t,Noeud_t) ;

/* ajoute en fils droit au noeud premier argumentle noeud second
   argument.

   CU: le fils droit doit \^etre vide sinon produit une erreur
*/
void AjouterFilsDroit(Noeud_t,Noeud_t) ;

/* remplace le fils gauche du noeud premier argument par le noeud
   second argument.
*/
void RemplacerFilsGauche(Noeud_t,Noeud_t) ;

/* remplace le fils droit du noeud premier argument par le noeud
   second argument.
*/
void RemplacerFilsDroit(Noeud_t,Noeud_t) ;

/* retourne le fils gauche du noeud premier argument */
Noeud_t FilsGauche(Noeud_t);

/* retourne le fils droit du noeud premier argument */
Noeud_t FilsDroit(Noeud_t);


