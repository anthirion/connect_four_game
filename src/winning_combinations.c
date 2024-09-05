/*
Ce fichier crée plusieurs combinaisons gagnantes au jeu puissance 4
et vérifie que ces combinaisons sont bien considérées comme gagnantes
par la fonction check_game_status
*/

#include "grid.h"
#include "constants.h"

unsigned diagonnally_winning_combinations() {
    unsigned test_number = 1;
    unsigned grid[6][7];
    init_grid(grid);

    // Diagonale montante
    play_token(grid, 0, YELLOW);
    play_token(grid, 1, RED);
    play_token(grid, 1, YELLOW);
    play_token(grid, 2, RED);
    play_token(grid, 1, YELLOW);
    play_token(grid, 2, RED);
    play_token(grid, 2, YELLOW);
    play_token(grid, 3, RED);
    play_token(grid, 2, YELLOW);
    play_token(grid, 3, RED);
    play_token(grid, 3, YELLOW);
    play_token(grid, 3, YELLOW);
    if (check_game_status(grid) == GAME_CONTINUE) {
        // Change la couleur du texte en rouge
        printf("\033[0;31m");
        printf("Diagonally test %d failed\n", test_number);
        // Réinitialise la couleur
        printf("\033[0m");
        return TEST_FAILED;
    }
    ++test_number;

    // Diagonale montante
    play_token(grid, 3, YELLOW);
    play_token(grid, 4, RED);
    play_token(grid, 4, YELLOW);
    play_token(grid, 5, RED);
    play_token(grid, 5, YELLOW);
    play_token(grid, 5, YELLOW);
    play_token(grid, 6, YELLOW);
    play_token(grid, 6, RED);
    play_token(grid, 6, YELLOW);
    play_token(grid, 6, YELLOW);
    if (check_game_status(grid) == GAME_CONTINUE) {
        printf("\033[0;31m");
        printf("Diagonally test %d failed\n", test_number);
        // Réinitialise la couleur
        printf("\033[0m");
        return TEST_FAILED;
    }
    ++test_number;

    // Diagonale montante
    play_token(grid, 6, YELLOW);
    play_token(grid, 5, RED);
    play_token(grid, 5, YELLOW);
    play_token(grid, 4, RED);
    play_token(grid, 4, YELLOW);
    play_token(grid, 4, RED);
    play_token(grid, 3, YELLOW);
    play_token(grid, 3, RED);
    play_token(grid, 5, YELLOW);
    play_token(grid, 2, RED);
    play_token(grid, 5, RED);
    if (check_game_status(grid) == GAME_CONTINUE) {
        printf("\033[0;31m");
        printf("Diagonally test %d failed\n", test_number);
        // Réinitialise la couleur
        printf("\033[0m");
        return TEST_FAILED;
    }
    ++test_number;

    // Diagonale descendante
    play_token(grid, 0, YELLOW);
    play_token(grid, 1, RED);
    play_token(grid, 1, YELLOW);
    play_token(grid, 5, RED);
    play_token(grid, 2, YELLOW);
    play_token(grid, 2, YELLOW);
    play_token(grid, 3, RED);
    play_token(grid, 1, YELLOW);
    play_token(grid, 2, RED);
    play_token(grid, 2, YELLOW);
    play_token(grid, 3, RED);
    play_token(grid, 3, YELLOW);
    play_token(grid, 4, RED);
    play_token(grid, 5, YELLOW);
    play_token(grid, 1, RED);
    if (check_game_status(grid) == GAME_CONTINUE) {
        printf("\033[0;31m");
        printf("Diagonally test %d failed\n", test_number);
        // Réinitialise la couleur
        printf("\033[0m");
        return TEST_FAILED;
    }
    ++test_number;

    // Diagonale descendante
    play_token(grid, 3, YELLOW);
    play_token(grid, 2, RED);
    play_token(grid, 2, YELLOW);
    play_token(grid, 1, RED);
    play_token(grid, 1, YELLOW);
    play_token(grid, 1, YELLOW);
    play_token(grid, 0, YELLOW);
    play_token(grid, 0, RED);
    play_token(grid, 0, YELLOW);
    play_token(grid, 0, YELLOW);
    if (check_game_status(grid) == GAME_CONTINUE) {
        printf("\033[0;31m");
        printf("Diagonally test %d failed\n", test_number);
        // Réinitialise la couleur
        printf("\033[0m");
        return TEST_FAILED;
    }
    ++test_number;

    // Diagonale descendante
    play_token(grid, 4, YELLOW);
    play_token(grid, 3, RED);
    play_token(grid, 3, YELLOW);
    play_token(grid, 2, RED);
    play_token(grid, 2, YELLOW);
    play_token(grid, 2, YELLOW);
    play_token(grid, 1, YELLOW);
    play_token(grid, 1, RED);
    play_token(grid, 1, YELLOW);
    play_token(grid, 1, YELLOW);
    if (check_game_status(grid) == GAME_CONTINUE) {
        printf("\033[0;31m");
        printf("Diagonally test %d failed\n", test_number);
        // Réinitialise la couleur
        printf("\033[0m");
        return TEST_FAILED;
    }
    
    return TEST_PASSED;

}

unsigned vertically_winning_combinations() {
    unsigned test_number;
    unsigned grid[6][7];
    init_grid(grid);

    for (unsigned column = 0; column < N_COLUMNS; column++) {
        test_number = 1;
        // Première combinaison gagnante: 4 jetons rouges
        for (unsigned cpt = 0; cpt < 4; cpt ++)
            play_token(grid, column, RED);
        // vérifier que cette combinaison est gagnante
        if (check_game_status(grid) == GAME_CONTINUE) {
            // Change la couleur du texte en rouge
            printf("\033[0;31m");
            printf("Vertical test %d at column %d failed\n", test_number, column);
            // Réinitialise la couleur
            printf("\033[0m");
            return TEST_FAILED;
        }
        ++test_number;
        
        // Deuxième combinaison gagnante: 1 jeton rouge, 1 jeton jaune et 4 jetons rouges
        play_token(grid, column, RED);
        play_token(grid, column, YELLOW);
        for (unsigned cpt = 0; cpt < 4; cpt ++)
            play_token(grid, column, RED);
        // vérifier que cette combinaison est gagnante
        if (check_game_status(grid) == GAME_CONTINUE) {
            // Change la couleur du texte en rouge
            printf("\033[0;31m");
            printf("Vertical test %d at column %d failed\n", test_number, column);
            // Réinitialise la couleur
            printf("\033[0m");
            return TEST_FAILED;
        }
        ++test_number;
        
        // Troisième combinaison gagnante: 1 jeton jaune et 4 jetons rouges
        play_token(grid, column, YELLOW);
        for (unsigned cpt = 0; cpt < 4; cpt ++)
            play_token(grid, column, RED);
        // vérifier que cette combinaison est gagnante
        if (check_game_status(grid) == GAME_CONTINUE) {
            // Change la couleur du texte en rouge
            printf("\033[0;31m");
            printf("Vertical test %d at column %d failed\n", test_number, column);
            // Réinitialise la couleur
            printf("\033[0m");
            return TEST_FAILED;
        }
        ++test_number;
        
        // Quatrième combinaison gagnante: 2 jetons jaunes et 4 jetons rouges
        for (unsigned cpt = 0; cpt < 2; cpt ++)
            play_token(grid, column, YELLOW);
        for (unsigned cpt = 0; cpt < 4; cpt ++)
            play_token(grid, column, RED);
        // vérifier que cette combinaison est gagnante
        if (check_game_status(grid) == GAME_CONTINUE) {
            // Change la couleur du texte en rouge
            printf("\033[0;31m");
            printf("Vertical test %d at column %d failed\n", test_number, column);
            // Réinitialise la couleur
            printf("\033[0m");
            return TEST_FAILED;
        }
    }
    return TEST_PASSED;
}

unsigned horizontally_winning_combinations() {
    unsigned test_number = 1;
    unsigned grid[6][7];
    init_grid(grid);

    // Première combinaison gagnante: 4 jetons rouge alignés sur la première ligne
    for (unsigned column = 0; column < 4; column++)
        play_token(grid, column, RED);
    // vérifier que cette combinaison est gagnante
    if (check_game_status(grid) == GAME_CONTINUE) {
        // Change la couleur du texte en rouge
        printf("\033[0;31m");
        printf("Horizontal test %d failed\n", test_number);
        // Réinitialise la couleur
        printf("\033[0m");
        return TEST_FAILED;
    }
    ++test_number;
    
    // Deuxième combinaison gagnante: 4 jetons rouge alignés sur la deuxième ligne
    // On remplit la première ligne
    for (unsigned column = 0; column < 3; column++)
        play_token(grid, column, RED);
    play_token(grid, 3, YELLOW);
    // On remplit la deuxième ligne
    for (unsigned column = 0; column < 4; column++)
        play_token(grid, column, RED);
    // vérifier que cette combinaison est gagnante
    if (check_game_status(grid) == GAME_CONTINUE) {
        // Change la couleur du texte en rouge
        printf("\033[0;31m");
        printf("Horizontal test %d failed\n", test_number);
        // Réinitialise la couleur
        printf("\033[0m");
        return TEST_FAILED;
    }

    return TEST_PASSED;
}

unsigned check_winning_combinations() {
    unsigned test_result;

    test_result = diagonnally_winning_combinations();
    if (test_result != TEST_PASSED)
        return TEST_FAILED;
    
    test_result = vertically_winning_combinations();
    if (test_result != TEST_PASSED)
        return TEST_FAILED;

    test_result = horizontally_winning_combinations();
    if (test_result != TEST_PASSED)
        return TEST_FAILED;

    return TEST_PASSED;
}

unsigned check_column_full_error() {
    // Vérifie que l'erreur COLUMN_FULL fonctionne correctement
    unsigned error;
    unsigned grid[6][7];
    init_grid(grid);

    // Remplir la colonne 0
    unsigned column = 0;
    for (unsigned cpt = 0; cpt < N_ROWS; cpt++)
        play_token(grid, column, RED);
    // Essayer d'ajouter un jeton dans la colonne pleine
    // Doit lever l'erreur COLUMN_FULL
    error = play_token(grid, column, RED);
    if (error != COLUMN_FULL)
        return TEST_FAILED;
    
    return TEST_PASSED;
}