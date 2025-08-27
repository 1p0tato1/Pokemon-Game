#ifndef BESTIAIRE_H
#define BESTIAIRE_H
#include "pokemonTypes.h"


void initBestiaire(EspecePokemon bestiaire[]);
void printBestiaire(EspecePokemon bestiaire[150]);
void triBestiaire(EspecePokemon bestiaire[]);
EspecePokemon chercherBestiaire(EspecePokemon bestiaire[], const char* nom);


#endif 