#include <iostream>

using namespace std;

struct PileFile{
    int valeur;
    PileFile *precedent;
    PileFile *suivant;
};

//empiler == enfiler
void empiler(PileFile *&pile,int nouvelleValeur){

    PileFile *nouveau = new PileFile;

    nouveau->valeur = nouvelleValeur;
    nouveau->precedent = NULL;
    nouveau->suivant = pile;

    if (pile != NULL){
        pile->precedent = nouveau;
    }
    pile = nouveau;
}
int depiler(PileFile *&pile){
    PileFile *courant = pile;
    int valeurDepilee;

    if(courant->suivant == NULL){
        valeurDepilee = courant->valeur;
        delete courant;
        pile = NULL;
    }else{
        courant->suivant->precedent = NULL;
        valeurDepilee = courant->valeur;
        pile = courant->suivant;
        delete courant;
    }
    return valeurDepilee;
}
int defiler(PileFile *&courant){
    int valeurDefilee;
    if(courant->suivant == NULL){
        valeurDefilee = courant->valeur;
        delete courant;
    }else{
        while(courant->suivant != NULL){
            courant = courant->suivant;
        }
        courant->precedent->suivant = NULL;
        valeurDefilee = courant->valeur;
        delete courant;
    }
    return valeurDefilee;
}
bool estVide(PileFile *&courant ){
    return true;
}
//taille
int taillePile(PileFile *&courant){
    int taille = 0;
    PileFile *temporaire = new PileFile;

    while (courant != NULL){
        empiler(temporaire,depiler(courant));
        ++taille;
    }
    while (temporaire != NULL){
        empiler(courant, depiler(temporaire));
    }
    return taille;
}
//affichage
void affichePileFile(PileFile *&pile, int taillePileFile){
    PileFile *courant = pile;

    for (int i = 0; i < taillePileFile; ++i) {
        std::cout<<"Precedent : "<<courant->precedent<<" Valeur : "<<courant->valeur<<" Suivant : "<<courant->suivant<<" Adresse maillon : "<<courant<<std::endl;
        courant = courant->suivant;
    }
}

int main() {
    //hello world
    cout << "Hello, World!" << endl;
    //creation d'une pile de test
    PileFile *test = NULL;
    PileFile *suivant = NULL;
    PileFile *precedent = NULL;
    //saisie des donness (stop si -1)
    int x;
    /*cout << "saisir la valeur :" ;
    cin >> x ;
    while (x != -1){
        empiler(test,x);
        cout << "saisir la valeur :" ;
        cin >> x ;
    }*/
    for (int i = 1; i <= 5; ++i) {
        empiler(test,i);
    }
    //Taille + Affichage
    cout << endl;
    cout <<"Taille de la PileFile : " << taillePile(test) << endl;
    cout << endl;
    affichePileFile(test, taillePile(test));
    return 0;
}
