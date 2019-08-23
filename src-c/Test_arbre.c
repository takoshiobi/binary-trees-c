#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ArbreBinaire.h"

#define max(a,b) ((a)>(b)?(a):(b))


/* Manipulation d'arbres binaires */

Noeud_t arbre1 (void) {
   	Noeud_t arbre,tmp  ;
	arbre = CreerNoeud(12) ;
	tmp = CreerNoeud(9) ;
	AjouterFilsGauche(arbre,tmp);
	tmp = CreerNoeud(8) ;
	AjouterFilsDroit(arbre,tmp);
    
    return arbre;
}

Noeud_t arbre2 (void) {
   	Noeud_t arbre,tmp  ;

	arbre = CreerNoeud(12) ;
	tmp = CreerNoeud(9) ;
	AjouterFilsGauche(arbre,tmp);
	tmp = FilsGauche(arbre);
	AjouterFilsDroit(tmp,CreerNoeud(5));
	tmp = FilsDroit(tmp);
	AjouterFilsGauche(tmp,CreerNoeud(7));
    
	return arbre;
}

Noeud_t arbre3 (void) {
   	Noeud_t arbre,tmp  ;

	arbre = CreerNoeud(12) ;
	tmp = CreerNoeud(9) ;
	AjouterFilsGauche(arbre,tmp);
	tmp = CreerNoeud(8) ;
	AjouterFilsDroit(arbre,tmp);
	tmp = FilsGauche(arbre);
	AjouterFilsGauche(tmp,CreerNoeud(1));
	AjouterFilsDroit(tmp,CreerNoeud(5));
	tmp = FilsDroit(arbre);
	AjouterFilsDroit(tmp,CreerNoeud(4));
	tmp = FilsDroit(tmp) ;
	AjouterFilsDroit(tmp,CreerNoeud(6));
	AjouterFilsGauche(tmp,CreerNoeud(7));
	    
    return arbre;
}

void imprimer (Noeud_t a) {
   if(a!=NULL){
        imprimer(a->filsgauche);
        printf("%ld ", a->val);
        imprimer(a->filsdroit);
    }
}

void preOrder(Noeud_t a){
    if(a!=NULL){
        printf("%ld ", a->val);
        preOrder(a->filsgauche);
        preOrder(a->filsdroit);
    }
}

int taille (Noeud_t a) {
   if(a==NULL){
       return 0;
   }
   else{
       return(taille(a->filsgauche) + 1 + taille(a->filsdroit));  
   }
}

int hauteur (Noeud_t a) {
   if(a==NULL){
       return 0;
   }
   else {
       int lHauteur = hauteur(a->filsgauche);
       int rHauteur = hauteur(a->filsdroit);
       if(lHauteur>rHauteur)
           return(lHauteur+1);
       else return (rHauteur+1);
   }
}

int nbFeuilles(Noeud_t a) {
   int count=0;
   if (a->filsgauche == NULL && a->filsdroit == NULL)
        count++;
   else{
       if(a->filsgauche != NULL)
           count += nbFeuilles(a->filsgauche);
       if(a->filsdroit != NULL)
           count += nbFeuilles(a->filsdroit);
   }
return count;  
}


/* Comptage d'arbres */

unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{   
    int i;
    unsigned long int res = 1;
      if (k > n - k)
        k = n - k;
      for ( i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
/* on utilise cette fonction pour calculer nb arbres binaires*/
unsigned long factorial(unsigned long f)
{
    if ( f == 0 ) 
        return 1;
    return(f * factorial(f - 1));
}

/* nb Arbres binaires de recherche */
int nbArbresRecherche(int n) {
   unsigned long int c = binomialCoeff(2*n, n);
   return c/(n+1); /* *factorial(n); */
}

int nbArbres(int n) {
   unsigned long int c = binomialCoeff(2*n, n);
   return c/(n+1)*factorial(n);
}

int nbArbresEfficace(int n){
    int tab[100]; /*100 valeurs pour stocker dans le tableau;*/
    int i;
    unsigned long int c = binomialCoeff(2*n, n);
    for(i=0;i<n;i++){
        tab[i]=factorial(i);
        return c/(n+1)*tab[i];
    }
    
}
    
/* Manipulation d'arbres binaires de recherche */

Noeud_t abr1 (void) {
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
    
    return arbre;
}

Noeud_t ajouter (Noeud_t a, value_t val) {
    if (a == NULL) 
        return CreerNoeud(val);
 
    if (val < a->val)
        a->filsgauche  = ajouter(a->filsgauche, val);
    else if (val > a->val)
        a->filsdroit = ajouter(a->filsdroit, val);   
 
    return a;
}

Noeud_t abr2 (void) {
    Noeud_t arbre;
    arbre = CreerNoeud(5) ;
    ajouter(arbre,4);
    ajouter(arbre,2);
    ajouter(arbre,7);
    ajouter(arbre,6);
    ajouter(arbre,1);
    return arbre;
    
    /*	Noeud_t arbre,tmp  ;

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
    
    return arbre; */
}

Noeud_t abr3 (void) {
   	Noeud_t arbre;
    arbre = CreerNoeud(7);
    ajouter(arbre,1);
    ajouter(arbre,4);
    ajouter(arbre,5);
    ajouter(arbre,6);
    ajouter(arbre,2);
	/*arbre = CreerNoeud(7) ;
	tmp = CreerNoeud(1) ;
	AjouterFilsGauche(arbre,tmp);
	tmp = FilsGauche(arbre);
    AjouterFilsDroit(tmp,CreerNoeud(4));
    tmp=FilsDroit(tmp);
    AjouterFilsDroit(tmp,CreerNoeud(5));
    AjouterFilsGauche(tmp,CreerNoeud(2));
    tmp=FilsDroit(tmp);
    AjouterFilsDroit(tmp,CreerNoeud(6));
    */
    return arbre;
}

int appartient (Noeud_t a, value_t v) {
    if(a==NULL){
        return 0;
    }
    else if(v == a->val){
        return 1;
    }
    else if(v < a->val){
        return appartient(a->filsgauche, v);
    }
    else{
        return appartient(a->filsdroit,v);
    }
    
}


int valeur_maximale (Noeud_t abr) {
   int res,lres,rres;
   if(abr == NULL){
       return 0;
   }
   res = abr ->val;
   lres = valeur_maximale(abr->filsgauche);
   rres = valeur_maximale(abr->filsdroit);
   if(lres>res)
       res=lres;
   if(rres>res)
       res=rres;
    return res;
}

int valeur_minimale (Noeud_t abr) {
   int res,rres,lres;
   if(abr==NULL)
       return 0;
    res=abr->val;
    lres=valeur_minimale(abr->filsgauche);
    rres=valeur_minimale(abr->filsdroit);
    if(lres<res)
        res=lres;
    if(rres < res)
        res=rres;
    return res;
}

/* True si arbre est ABR False sinon */
int isABR(Noeud_t abr) 
{ 
  if (abr == NULL) 
    return(true); 
     
  if (abr->filsgauche!=NULL && valeur_maximale(abr->filsgauche) > abr->val) 
    return(false); 
     
  if (abr->filsdroit!=NULL && valeur_minimale(abr->filsdroit) < abr->val) 
    return(false); 
   
  if (!isABR(abr->filsgauche) || !isABR(abr->filsdroit)) 
    return(false); 
  return(true); 
} 

/* Entier mysterieux */

Noeud_t construitArbreEntierMysterieux (value_t i, value_t j) { 
   Noeud_t arbre;
   /*/int arr[64];
   //int len;*/
   arbre = CreerArbreVide();
   /*strand(time(NULL));
   //len = j-i;*/
   for(i=0;i<j;i++){
       /*arr[i]=i;
       //int randomIndex = rand() % len;
       //int randomValue = arr[randomIndex];*/
       ajouter(arbre,i);
   }
   return (arbre);    
}

void jouer (int n) {
   ;
}

/* Tests sur les arbres binaires */

void testArbreBinaire(Noeud_t a) {
   imprimer(a); printf("\n");
   printf("Taille     = %d\n",(taille(a)));
   printf("Hauteur    = %d\n",(hauteur(a)));
   printf("nbFeuilles = %d\n",(nbFeuilles(a)));
}

/* Tests sur les arbres binaires de recherche */
void testABR (Noeud_t a) {
   int i;
   imprimer(a); printf("\n");
   printf("preOrder values : "); preOrder(a); printf("\n");
   printf("Taille     = %d\n",(taille(a)));
   printf("Hauteur    = %d\n",(hauteur(a)));
   printf("nbFeuilles = %d\n",(nbFeuilles(a)));
   printf("Valeurs présentes dans l'arbre : ");
   for (i = 1; i <= 10; i++) {
      if (appartient(a,i)) {
         printf("%d ",i);
      }
   }
   printf("\n");
}
  
/* Programme principal */
int main (int argc, char **argv) {

   int i,k;
   
   testArbreBinaire(arbre1());
   testArbreBinaire(arbre2());
   testArbreBinaire(arbre3());

   for (i = 0; i <= 19; i++) {
      printf("Le nombre d'arbres à %d noeuds est %d\n",i,(nbArbres(i)));
   } 
   printf("\n");
   for (k = 0; k <= 19; k++) {
      printf("Le nombre d'ABR à %d noeuds est %d\n",i,(nbArbresRecherche(k)));
   } 
  
   testABR(abr1());
   testABR(abr2());
   testABR(abr3());

   printf("Arbre mysterieux entre 12 et 24:\n");
   imprimer(construitArbreEntierMysterieux(12,24));
   printf("\n");
  
   jouer(100);

   return 0;
   
}
