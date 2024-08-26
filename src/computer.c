#include "computer.h"

/*
Tableau stockant le score de chaque colonne
Le score d'une colonne correspond au nombre de jetons de la couleur jouée par
l'ordinateur si ce dernier décide de jouer dans cette colonne.
Le score d'une colonne est forcément positif ou nul.
*/
static unsigned moves_scores[7];

void compute_column_scores(int grid[6][7]) {
    /*
    Complète le tableau moves_scores en calculant le score de chaque colonne
    */
}

int play() {
    /*
    Retourne la colonne ayant le score maximal
    */
    return 1; 
}