using namespace std;
#include <iostream>
#include "pokedex.h"
#include <cstring> 
#include <cstdlib>
#include <ctime>


Pokedex* initPokedex(const int size){
    Pokedex* pokedex = new Pokedex;
    pokedex->capacity = size;
    pokedex->nbPokemons = 0;
    pokedex->mesPokemons = new Pokemon[size]; // 
    return pokedex;
}


void insertPokemon(Pokedex* pokedex, Pokemon p) {


    // 1- A-t-on assez de place dans la tabeau dynamique ?
    if (pokedex->capacity == pokedex->nbPokemons) {

        // le tableau dynamique est plein,
        // on va commencer par l'aggrandir de 50% de sa capacité
        const int new_capacity = (int)pokedex->capacity * 1.5;
        Pokemon* bigger_pokemon_tab = new Pokemon[new_capacity];
        for (int i = 0; i < pokedex->nbPokemons; i++) {
            bigger_pokemon_tab[i] = pokedex->mesPokemons[i];
        }

        // le tableau de pokemons devient celui nouvellement construit contenant les anciens pokemons.
        pokedex->mesPokemons = bigger_pokemon_tab;

        // sa capacite est mise à jour
        pokedex->capacity = new_capacity;

    }

    // 2- on cherche l'index auquel nous allons insérer ce
    // nouveau pokemon, au regard de son nom (tri par ordre
    // croissant des noms de pokemon).
    if (pokedex->nbPokemons == 0) {
        pokedex->mesPokemons[0] = p;
    }
    else {
        // au moins un pokemon, cherchons la position du
        // nouveau pokemon.
        int i = 0;
        while (i < pokedex->nbPokemons && strcmp(pokedex->mesPokemons[i].nom, p.nom) < 0) {
            i++;
        }

        // on quitte la boucle car il faut l'insérer à la fin, ou en cours de tableau
        // suivant si on a quitté car i == pokedex->nbPokemons ou si on a trouvé un pokemon
        // après le pokemon $p$ dnas l'ordre alphabétique.
        if (i == pokedex->nbPokemons) {
            pokedex->mesPokemons[i] = p;
        }
        else {
            // il faut décaler les pokemons du sous tableau partant de la droite du
            // tbaleau afin d'y faire un trou dans le tableau et y placr notre pokemon.
            // Voir principe du tri par insertion vu en module BCD algorithmie.
            for (int k = pokedex->nbPokemons - 1; k >= i; k--) {
                pokedex->mesPokemons[k + 1] = pokedex->mesPokemons[k];
            }
            pokedex->mesPokemons[i] = p;
        }
    }

    pokedex->nbPokemons = pokedex->nbPokemons + 1;
}

void displayPokedex(Pokedex* pokedex, EspecePokemon bestiaire[150], const char * typesLabel[18]){
    cout << endl << "Contenu du pokedex (Actuellement ";
    cout << pokedex->nbPokemons << " pokemons captures)" << endl;
    for (int i = 0; i < pokedex->nbPokemons; i++) {
        display(pokedex->mesPokemons[i], bestiaire, typesLabel);
        cout << "--------------------------" << endl;
    }

}

Pokemon genererPokemon(EspecePokemon bestiaire[150], char* typesLabel[18]){
    Pokemon pokemonSauvage ;
    srand(time(0));
    int randomNumber;
    do {
        randomNumber = rand() % 150;
    } while (bestiaire[randomNumber].estEvolue == true);
    pokemonSauvage.nom = bestiaire[randomNumber].nom;
    pokemonSauvage.XP = 0;
    randomNumber = rand() % 800;
    pokemonSauvage.CP = randomNumber + 200;
    randomNumber = rand() % 470;
    pokemonSauvage.PV = randomNumber + 30;
    pokemonSauvage.evolution = 0;
    cout << endl;
    cout << "Un pokemon sauvage vient d'apparaitre !" << endl;
    cout << "Nom : " << pokemonSauvage.nom << endl;
    cout << "Type : " << typesLabel[bestiaire[randomNumber].type] << endl;
    cout << "CP : " << pokemonSauvage.CP << endl;
    cout << "PV : " << pokemonSauvage.PV << endl;
    cout << "XP : " << pokemonSauvage.XP << endl;
    cout << "Evolution : " << pokemonSauvage.evolution << endl;
    cout << endl; 
    
}

