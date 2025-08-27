using namespace std;
#include <iostream>
#include "pokemon.h"
#include "bestiaire.h"

void evolve(Pokemon& p) {
	p.evolution++;
}

void powerup(Pokemon& p) {
	int val = p.CP * 0.25;
	p.CP += val;
}

void display(const Pokemon p, EspecePokemon bestiaire[], const char* typesLabel[18]) {
	cout << " Nom : " << p.nom << endl;
	EspecePokemon infosPokemon = chercherBestiaire(bestiaire, p.nom);
	cout << " Type : " << typesLabel[infosPokemon.type] << endl;
	cout << " XP : " << p.XP  << endl;
	cout << " Evolution : " << p.evolution  << endl;
	cout << " PV : " << p.PV <<  endl;
	cout << " CP : " << p.CP << endl;
}