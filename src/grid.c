#include "grid.h"
#include "constants.c"

enum color { YELLOW, RED };

/*
La grille est composée de 6 lignes et 7 colonnes.
Chaque case de la grille peut contenir 3 valeurs possibles :
    - la valeur YELLOW_TOKEN indique qu'un jeton de couleur jaune est
    présent sur la case,
    - la valeur RED_TOKEN indique qu'un jeton de couleur rouge est
    présent sur la case,
    - la valeur NO_TOKEN indique qu'aucun jeton n'est présent sur la case.
*/

void init_grid(int grid[6][7]) {
    /*
    Place des -1 dans toute la grille, indiquant l'absence de jetons
    */
}

int play_token(int grid[6][7], int column, enum color) {
    /*
    Place un jeton de la couleur {color} dans la colonne {column}.
    L'entier renvoyé indique si une erreur s'est produite ou non :
        - NO_ERROR => pas d'erreur
        - COLUMN_FULL => la colonne est pleine
        (la valeur des constantes est définie dans constants.c)
    On considère ici que le numéro de la colonne est valide, puisqu'il
    a déjà été vérifié dans une fonction du fichier interactions.c.
    On considère que la couleur du jeton ne peut pas être incorrecte
    car gérée par l'ordinateur et pas choisie par l'utilisateur (par
    défaut le joueur 1 se verra attribuée la couleur 0, jaune, et le
    joueur 2 la couleur 1, rouge).
    */
    return NO_ERROR;
}

int game_finished(int grid[6][7]) {
    /*
    Vérifie si 4 jetons de la même couleur sont alignés ou si toute
    la grille est remplie (les 2 conditions d'arrêt du jeu) ou encore
    si un des 2 joueurs décide d'arrêter le jeu en tapant F.
    Valeur de retour :
        - GAME_CONTINUE : jeu non-terminé
        - PLAYER_1_WON : jeu terminé, le joueur 1 a gagné
        - PLAYER_2_WON : jeu terminé, le joueur 2 a gagné
        - GAME_INTERRUPTED_BY_PLAYER: jeu terminé par un des 2 joueurs
        (la valeur des constantes est définie dans constants.c)
    */
    return GAME_CONTINUE;
}