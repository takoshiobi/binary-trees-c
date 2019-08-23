#include "ArbreBinaire.h"
#include "Affichage.h"

int
main
(void)
{
	Noeud_t arbre,tmp  ;

	arbre = CreerNoeud(5) ;
	tmp = CreerNoeud(4) ;
	AjouterFilsGauche(arbre,tmp);
	tmp = CreerNoeud(7) ;
	AjouterFilsDroit(arbre,tmp);
	tmp = FilsGauche(arbre);
	AjouterFilsGauche(tmp,CreerNoeud(2));
    tmp=FilsGauche(tmp);
    AjouterFilsGauche(tmp,CreerNoeud(1));
    
    tmp=FilsDroit(arbre);
    AjouterFilsGauche(tmp,CreerNoeud(6));
	
	SauverArbreDansFichier(arbre,"abr2");
	
	return 0 ;
}
