using namespace std;
#include <iostream>
#include "pokemon.h"
#include "bestiaire.h"
#include "pokedex.h"


void menu() {
	cout << "1 - Index des pokemons " << endl;
	cout << "2 - Mon Pokedex " << endl;
	cout << "3 - Attraper un pokemon " << endl;
	cout << "4 - Power-up et evolution " << endl;
	cout << "5 - Combat " << endl;
	cout << "6 - Quitter " << endl;
	cout << "Please choose a number between 1 and 6 " << endl;
};

int main() {
	cout << "Hello player !" << endl;
	EspecePokemon bestiaire[150];
    initBestiaire(bestiaire);
    
    const char* typesLabel[18] = {"Normal", "Fighting", "Flying", "Poison", "Ground", "Rock", "Bug", "Ghost", "Steel", "Fire", "Grass", "Water", "Electric", "Psychic", "Ice", "Dragon", "Dark", "Fairy"};
    
    Pokedex* pokedex = initPokedex(4);
    Pokemon a;
    a.nom = "Seadra";
    a.XP = 1;
    a.CP = 4;
    a.evolution = 1;
    a.PV = 23;
    
    Pokemon b;
    b.nom = "Arbok";
    b.XP = 0;
    b.CP = 123;
    b.evolution = 2;
    b.PV = 134;
    
    Pokemon c;
    c.nom = "Zubat";
    c.XP = 40;
    c.CP = 300;
    c.evolution = 1;
    c.PV = 223;
    
    Pokemon d;
    d.nom = "Paras";
    d.XP = 0;
    d.CP = 23;
    d.evolution = 1;
    d.PV = 90;
    
    Pokemon e;
    e.nom = "Arkanine";
    e.XP = 0;
    e.CP = 23;
    e.evolution = 2;
    e.PV = 290;
    
    insertPokemon(pokedex, a);
    cout << "******* Pokedex after inserting pokemon a *********" << endl;
    displayPokedex(pokedex, bestiaire, typesLabel);
    cout << "***************************************************" << endl << endl << endl;
    
    insertPokemon(pokedex, b);
    cout << "******* Pokedex after inserting pokemon b *********" << endl;
    displayPokedex(pokedex, bestiaire, typesLabel);
    cout << "***************************************************" << endl << endl << endl;
    
    insertPokemon(pokedex, c);
    cout << "******* Pokedex after inserting pokemon c *********" << endl;
    displayPokedex(pokedex, bestiaire, typesLabel);
    cout << "***************************************************" << endl << endl << endl;
    
    insertPokemon(pokedex, d);
    cout << "******* Pokedex after inserting pokemon d *********" << endl;
    displayPokedex(pokedex, bestiaire, typesLabel);
    cout << "***************************************************" << endl << endl << endl;
    
    insertPokemon(pokedex, e);
    cout << "******* Pokedex after inserting pokemon e *********" << endl;
    displayPokedex(pokedex, bestiaire, typesLabel);
    cout << "***************************************************" << endl << endl << endl;

	menu();

	int entreeJoueur;
	
	do {
		cin >> entreeJoueur;
		switch (entreeJoueur) {
			case 1:
				cout << "1 - Affichage par ordre naturel " << endl;
				cout << "2 - Affichage trie " << endl;
				cout << "3 - Retour en arri�re " << endl;
				cout << "4 - Quitter le jeu " << endl;
				int entreeJoueur2;
				do {
					cin >> entreeJoueur2;
					switch (entreeJoueur2) {
					case 1:
						printBestiaire(bestiaire);
						break;
					case 2:
						triBestiaire(bestiaire);
						break;
					case 3:
						menu();
						break;
					default:
						break;
					}
				} while (entreeJoueur2 != 4);
				break;
			case 2:
                displayPokedex(pokedex, bestiaire, typesLabel);
				break;
			case 3:
				break;
			case 4:
				cout << "1 - Power-up " << endl;
				cout << "2 - Evolution " << endl;
				cout << "3 - Retour en arriere " << endl;
				cout << "4 - Quitter le jeu " << endl;
				int entreeJoueur1;
				do {
					cin >> entreeJoueur1;
					switch (entreeJoueur1) {
						case 1:
							powerup(a); 
							break;
						case 2:
							evolve(a);
							break;
						case 3:
							menu();
							break;
						default:
							break;
					}
				} while (entreeJoueur1 != 4);
				break;
			case 5:
				break;
			case 6:
				break;
			default:
				break;
		}
	} while (entreeJoueur != 6);
	cout << "Ciaaaao";
	return 0;
	}