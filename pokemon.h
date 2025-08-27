#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include "bestiaire.h"


struct Pokemon {
	const char* nom;
	int XP;
	int evolution;
	int PV;
	int CP;
};

void evolve(Pokemon& p);
void powerup(Pokemon& p);
void display(const Pokemon p, EspecePokemon bestiaire[], const char* typesLabel[18]);

#endif 