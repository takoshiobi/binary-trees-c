#include "ArbreBinaire.h"
#include "Affichage.h"

int
main
(void)
{
	Noeud_t arbre,tmp  ;

	arbre = CreerNoeud(12) ;
	tmp = CreerNoeud(9) ;
	AjouterFilsGauche(arbre,tmp);
	tmp = FilsGauche(arbre);
	AjouterFilsDroit(tmp,CreerNoeud(5));
	tmp = FilsDroit(tmp);
	AjouterFilsGauche(tmp,CreerNoeud(7));
	SauverArbreDansFichier(arbre,"exemple3");
	
	return 0 ;
}
