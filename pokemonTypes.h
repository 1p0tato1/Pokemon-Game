#ifndef POKEMONTYPES_H
#define POKEMONTYPES_H


// le type enuméré décrivant le type de Pokemon parmi les 18 existants
typedef enum { Normal, Fighting, Flying, Poison, Ground, Rock, Bug, Ghost, Steel, Fire, Grass, Water, Electric, Psychic, Ice, Dragon, Dark, Fairy } PokemonType;

struct EspecePokemon {
	const char* nom;
	PokemonType type;
	int nbBonbonsPourEvoluer;
	const char* evolvesTo;
    bool estEvolue ;
};

#endif 