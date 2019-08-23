#include "ArbreBinaire.h"
#include "Affichage.h"

int
main
(void)
{
	Noeud_t arbre,tmp  ;

	arbre = CreerNoeud(7) ;
	tmp = CreerNoeud(1) ;
	AjouterFilsGauche(arbre,tmp);
	tmp = FilsGauche(arbre);
    AjouterFilsDroit(tmp,CreerNoeud(4));
    tmp=FilsDroit(tmp);
    AjouterFilsDroit(tmp,CreerNoeud(5));
    AjouterFilsGauche(tmp,CreerNoeud(2));
    tmp=FilsDroit(tmp);
    AjouterFilsDroit(tmp,CreerNoeud(6));
	
	SauverArbreDansFichier(arbre,"abr3");
	return 0 ;
}
