#include "computer.h"

static const enum color COMPUTER_TOKEN_COLOR = RED;

/*
Tableau stockant le score de chaque colonne
Le score d'une colonne correspond au nombre de jetons de la couleur jouée par
l'ordinateur si ce dernier décide de jouer dans cette colonne.
Le score d'une colonne est forcément positif ou nul.
*/
static unsigned moves_scores[7];

void undo_move(unsigned grid[6][7], const unsigned column) {
    unsigned row = 0;
    // Trouver la première ligne non-vide dans la colonne
    while (row < N_ROWS && grid[row][column] == NO_TOKEN)
        row++;
    grid[row][column] = NO_TOKEN;
}

unsigned check_winning_move(unsigned grid[6][7]) {
    for (unsigned column = 0; column < N_COLUMNS; column++) {
        // Simuler un coup de l'ordinateur dans la colonne 'column'
        // L'ordinateur joue toujours un jeton rouge
        if (play_token(grid, column, RED) == NO_ERROR) {
            // Vérifier si ce coup mène à une victoire
            if (check_game_status(grid) != GAME_CONTINUE) {
                undo_move(grid, column); // Annuler le coup après vérification
                return column; // Retourne la colonne gagnante
            }
            undo_move(grid, column);
        }
        else {
            // Change la couleur du texte en rouge
            printf("\033[0;31m"); 
            printf("INTERNAL ERROR: PLAY TOKEN NOT WORKING\n");
            // Réinitialise la couleur
            printf("\033[0m"); 
        }
    }
    return NO_WINNING_MOVE;
}

void compute_column_scores(unsigned grid[6][7]) {
    /*
    Complète le tableau moves_scores en calculant le score de chaque colonne
    */
   for (unsigned col = 0; col < N_COLUMNS; col++) {
        // Trouver la première ligne non-vide dans la colonne
        unsigned row = 0;
        while (row < N_ROWS && grid[row][col] == NO_TOKEN)
            row++;
        // Si la colonne est pleine, score = 0
        if (row == 0)
            moves_scores[col] = 0;
        // Récupérer la couleur du jeton
        unsigned value = grid[row][col];
        // Calculer combien de pièces seraient alignées verticalement
        int vertical_count = 1; // Le jeton lui-même
        row++;                  // Le jeton a déjà été compté
        // Compter le nombre de jetons de la même couleur en dessous
        while (row < N_ROWS && grid[row][col] == value) {
            row++;
            vertical_count++;
        }
        // Stocker le score pour la colonne
        moves_scores[col] = vertical_count;
    }
}

void display_scores(unsigned moves_scores[7]) {
    printf("Computed scores: \t");
    for (unsigned index = 0; index < 7; index++)
        printf("%u ", moves_scores[index]);
    printf("\n");
}

unsigned get_max_score_column(unsigned moves_scores[7]) {
    unsigned max_score = 0, max_score_column = 0;

    for (unsigned col = 0; col < 7; col++) {
        if (moves_scores[col] > max_score) {
            max_score = moves_scores[col];
            max_score_column = col;
        }
    }
    return max_score_column;
}

unsigned play(unsigned grid[6][7]) {
    /*
    Retourne la colonne ayant le score maximal
    */
    unsigned winning_move = check_winning_move(grid);
    if (winning_move == NO_WINNING_MOVE) {
        compute_column_scores(grid);
        unsigned max_score_column = get_max_score_column(moves_scores);
        if (play_token(grid, max_score_column, COMPUTER_TOKEN_COLOR) == COLUMN_FULL)
            return COLUMN_NUMBER_ERROR;
    }
    else {
        if (play_token(grid, winning_move, COMPUTER_TOKEN_COLOR) == COLUMN_FULL)
            return COLUMN_NUMBER_ERROR;
    }

    return NO_ERROR; 
}