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
    char buffer[100];
    
column_choice:
    printf("Choisissez le numéro de colonne où placer le jeton: \t");
    // Boucle tant que l'entrée n'est pas un entier valide entre 1 et 7
    while (1) {
        if (scanf("%d", &column) != 1 || column < 1 || column > 7) {
            // Si l'entrée n'est pas valide, vider le buffer et afficher un message d'erreur
            fgets(buffer, sizeof(buffer), stdin);  // Consomme les données restantes du buffer
            printf("Veuillez entrer un entier entre 1 et 7 inclus\n");
            printf("Entrez à nouveau un numéro de colonne: \t");
        } else {
            break;  // Si l'entrée est correcte, sortir de la boucle
        }
    }

    // Vérifier si la colonne est pleine
    if (play_token(grid, --column, color) == COLUMN_FULL) {
        printf("La colonne que vous essayez de remplir est pleine\n");
        printf("Entrez une autre colonne\n");
        goto column_choice;
    }
}