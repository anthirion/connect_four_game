#include "human_game.h"

void play_with_human(unsigned grid[6][7]) {
    /*
    Boucle infinie qui définie le comportement du jeu avec 2 joueurs humain.
    */
    unsigned game_status, round_number = 0;

    do {
        printf("\nTOUR %d\n", round_number + 1);
        printf("C'est au joueur %d de jouer !\n", (round_number % 2) + 1);
        display_grid(grid);
        if (round_number % 2 == 0)
            // C'est au joueur 2 de jouer
            choose_column(grid, YELLOW);
        else
            // C'est au joueur 1 de jouer
            choose_column(grid, RED);
        game_status = check_game_status(grid);
        ++round_number;
    } while (game_status == GAME_CONTINUE);

    // Afficher la grille gagnante lors de la victoire
    display_grid(grid);

    if (game_status == PLAYER_1_WON) {
        // Change la couleur du texte en vert
        printf("\033[0;32m");
        printf("Le joueur 1 a gagné !\n\n");
        // Réinitialise la couleur
        printf("\033[0m");
    }
    else if (game_status == PLAYER_2_WON) {
        // Change la couleur du texte en vert
        printf("\033[0;32m");
        printf("Le joueur 2 a gagné !\n\n");
        // Réinitialise la couleur
        printf("\033[0m");
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