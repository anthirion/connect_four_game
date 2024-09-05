#include "interactions.h"
#include "grid.h"

void choose_column(unsigned grid[6][7], enum color color) {
    /*
    Affiche une invitation à l'utilisateur de choisir un numéro
    de colonne.
    [ATTENTION] Le numéro de colonne entré par l'utilisateur est entre 1 et 7.
    Il doit être décrémenté de 1 pour être entre 0 et 6.
    */
    int column;
    unsigned error;
column_choice:
    printf("Choisissez le numéro de colonne où placer le jeton: \t");
    while (scanf("%d", &column) != 1 || column < 1 || column > 7) {
        printf("Veuillez entrer un entier entre 1 et 7 inclus\n");
        printf("Entrez à nouveau un numéro de colonne: \t");
    }
    // ATTENTION: changer la couleur du jeton en fonction du joueur qui joue
    error = play_token(grid, --column, color);
    if (error == COLUMN_FULL) {
        printf("La colonne que vous essayez de remplir est pleine\n");
        printf("Entrez une autre colonne\n");
        goto column_choice;
    }
}