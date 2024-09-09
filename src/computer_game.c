#include "computer_game.h"

void play_with_computer(unsigned short grid[6][7]) {
    /*
    Boucle infinie qui définie le comportement du jeu avec 2 joueurs humain.
    */
    unsigned short game_status, round_number = 1;

    do {
        printf("\nTOUR %d\n", round_number);
        display_grid(grid);
        if (round_number % 2 == 1) {
            printf("C'est à vous de jouer !\n");
            choose_column(grid, YELLOW);
        }
        else {
            printf("C'est à l'ordinateur de jouer !\n");
            play(grid);
        }
        game_status = check_game_status(grid);
        ++round_number;
    } while (game_status == GAME_CONTINUE);

    // Afficher la grille gagnante lors de la victoire
    display_grid(grid);

    if (game_status == PLAYER_1_WON) {
        // Change la couleur du texte en vert
        printf("\033[0;32m");
        printf("Vous avez gagné !\n\n");
        // Réinitialise la couleur
        printf("\033[0m");
    }
    else if (game_status == PLAYER_2_WON) {
        printf("L'ordinateur a gagné !\n\n");
    }
    else {
        // Change la couleur du texte en rouge
        printf("\033[0;31m"); 
        printf("INTERNAL ERROR: GAME_STATUS INCORRECT\n");
        // Réinitialise la couleur
        printf("\033[0m");
        // Génère un core file
        abort();  
    }
}