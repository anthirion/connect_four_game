#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "winning_combinations.h"
#include "human_game.h"
#include "computer_game.h"

int main() {
    char buffer[5];
    unsigned short grid[N_ROWS][N_COLUMNS];
    init_grid(grid);

    // For test purposes
    // unsigned short test_result;
    // test_result = check_winning_combinations();
    // if (test_result != TEST_PASSED)
    //     return EXIT_FAILURE;
    // test_result = check_winning_combinations();
    // if (test_result != TEST_PASSED)
    //     return EXIT_FAILURE;
    // // Change la couleur du texte en vert
    // printf("\033[0;32m");
    // printf("ALL TEST PASSED !\n");
    // // Réinitialise la couleur
    // printf("\033[0m");

    // Choix de l'utilisateur pour jouer contre l'ordinateur
    printf("Voulez-vous jouer contre l'ordinateur (entrez oui ou non) ?\t");
    while (scanf("%s", buffer) != 1 || (strcmp(buffer, "oui") != 0 && strcmp(buffer, "non") != 0)) {
        printf("\nEntrez oui ou non: \t");
    }

    if (strcmp(buffer, "non") == 0) {
        play_with_human(grid);
    }
    else if (strcmp(buffer, "oui") == 0) {
        play_with_computer(grid);
    }
    
    return EXIT_SUCCESS;
}