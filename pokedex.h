#ifndef POKEDEX_H
#define POKEDEX_H
#include "pokemon.h"

struct Ressource {
	int poussieres;
	int bonbons;
};

typedef struct{
    Pokemon* mesPokemons;  // tableau dynamique de pokemons
    int capacity;  // capacité maximale du tableau
    int nbPokemons;  // nombre de pokemon dans le tableau jusqu'à maintenant.
} Pokedex;

Pokedex* initPokedex(const int size);
void insertPokemon(Pokedex* monPokedex, Pokemon p);
void displayPokedex(Pokedex* pokedex, EspecePokemon bestiaire[150], const  char * typesLabel[18]);

#endif 