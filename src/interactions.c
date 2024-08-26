#include "interactions.h"
#include "constants.c"

int choose_column() {
    /*
    Affiche une invitation à l'utilisateur de choisir un numéro
    de colonne.
    [ATTENTION] Le numéro de colonne entré par l'utilisateur (entre 1 et 7)
    est décrémenté de 1 pour être entre 0 et 6.
    L'entier renvoyé indique si une erreur s'est produite ou non :
        - NO_ERROR => pas d'erreur
        - COLUMN_NUMBER_ERROR => le numéro de colonne est invalide
    */
    return NO_ERROR;
}

int finish_game() {
    /*
    Cette fonction vérifie en boucle que l'utilisateur ne clique pas sur F
    pour terminer le jeu.
    Valeur de retour :
        - GAME_CONTINUE si le joueur n'a pas cliqué sur F
        - GAME_INTERRUPTED_BY_PLAYER si le joueur a cliqué sur F
    */
   return GAME_CONTINUE;
}