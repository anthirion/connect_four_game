#include <stdlib.h>
#include <stdio.h>

#include "grid.h"
#include "winning_combinations.h"
#include "interactions.h"

int main() {
    unsigned game_status, round_number = 1;
    unsigned grid[6][7];
    init_grid(grid);

    // For test purposes
    unsigned test_result;
    test_result = check_winning_combinations();
    if (test_result != TEST_PASSED)
        return EXIT_FAILURE;
    test_result = check_winning_combinations();
    if (test_result != TEST_PASSED)
        return EXIT_FAILURE;
    // Change la couleur du texte en vert
    printf("\033[0;32m");
    printf("ALL TEST PASSED !\n");
    // Réinitialise la couleur
    printf("\033[0m");

    // Main game loop
    do {
        printf("TOUR %d\n", round_number);
        printf("C'est au joueur %d de jouer !\n", (round_number % 2) + 1);
        display_grid(grid);
        if (round_number % 2 == 0)
            // C'est au joueur 2 de jouer
            choose_column(grid, RED);
        else
            // C'est au joueur 1 de jouer
            choose_column(grid, YELLOW);
        game_status = check_game_status(grid);
        ++round_number;
    } while (game_status == GAME_CONTINUE);

    // Afficher la grille gagnante lors de la victoire
    display_grid(grid);

    if (game_status == PLAYER_1_WON) {
        printf("Le joueur 1 a gagné !\n\n");
    }
    else if (game_status == PLAYER_2_WON) {
        printf("Le joueur 2 a gagné !\n\n");
    }
    else {
        // Change la couleur du texte en rouge
        printf("\033[0;31m"); 
        printf("INTERNAL ERROR: GAME_STATUS INCORRECT\n");
        // Réinitialise la couleur
        printf("\033[0m");    
    }
    
    return EXIT_SUCCESS;
}