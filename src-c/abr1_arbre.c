#include "ArbreBinaire.h"
#include "Affichage.h"

int
main
(void)
{
	Noeud_t arbre,tmp  ;

	arbre = CreerNoeud(6) ;
	tmp = CreerNoeud(4) ;
	AjouterFilsGauche(arbre,tmp);
	tmp = CreerNoeud(7) ;
	AjouterFilsDroit(arbre,tmp);
	tmp = FilsGauche(arbre);
	AjouterFilsGauche(tmp,CreerNoeud(2));
	AjouterFilsDroit(tmp,CreerNoeud(5));
	tmp = FilsGauche(tmp);
	AjouterFilsGauche(tmp,CreerNoeud(1));
	
	SauverArbreDansFichier(arbre,"abr1");
	
	return 0 ;
}
