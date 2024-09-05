#include "computer.h"

#define MAX(a, b) (a) > (b) ? (a) : (b)

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
        unsigned result = play_token(grid, column, RED);
        if (result == NO_ERROR) {
            // Vérifier si ce coup mène à une victoire
            if (check_game_status(grid) != GAME_CONTINUE) {
                undo_move(grid, column); // Annuler le coup après vérification
                return column; // Retourne la colonne gagnante
            }
            undo_move(grid, column);
        }
        else if (result != COLUMN_FULL) {
            // Change la couleur du texte en rouge
            printf("\033[0;31m"); 
            printf("INTERNAL ERROR: PLAY TOKEN NOT WORKING\n");
            // Réinitialise la couleur
            printf("\033[0m"); 
            // Génère un core file
            abort();
        }
    }
    return NO_WINNING_MOVE;
}

void compute_column_scores(unsigned grid[6][7]) {
    /*
    Complète le tableau moves_scores en calculant le score de chaque colonne
    */
   for (unsigned col = 0; col < N_COLUMNS; col++) {
        unsigned result = play_token(grid, col, COMPUTER_TOKEN_COLOR);
        if (result == COLUMN_FULL)
            moves_scores[col] = 0;
        else if (result == NO_ERROR) {
            // Trouver la première ligne non-vide dans la colonne
            unsigned row = 0;
            while (row < N_ROWS && grid[row][col] == NO_TOKEN)
                row++;
            // Récupérer la couleur du jeton
            unsigned token = grid[row][col];
            unsigned start_row = row;
            unsigned start_col = col;
            // Calculer combien de pièces seraient alignées verticalement
            unsigned vertical_count = 0;
            unsigned horizontal_count = 0;
            unsigned diagonal_count = 0;
            // Compter le nombre de jetons de la même couleur sur la colonne
            while (row < N_ROWS && grid[row][col] == token) {
                row++;
                vertical_count++;
            }
            row = start_row;

            // Compter le nombre de jetons de la même couleur sur la ligne
            // Compte en 2 temps: les jetons à droite puis à gauche
            while (col < N_COLUMNS && grid[row][col] == token) {
                col++;
                horizontal_count++;
            }
            col = start_col - 1;
            while (col != (unsigned) - 1 && grid[row][col] == token) {
                col--;
                horizontal_count++;
            }
            row = start_row;
            col = start_col;

            // Compter le nombre de jetons de la même couleur sur la diagonale
            // Compte en 2 temps: les jetons sur diagonale montante puis descendante
            while (row < N_ROWS && col < N_COLUMNS && grid[row][col] == token){
                row++;
                col++;
                diagonal_count++;
            }
            row = start_row - 1;
            col = start_col - 1;
            while (row != (unsigned) - 1 && col != (unsigned) - 1 && grid[row][col] == token){
                row--;
                col--;
                diagonal_count++;
            }
            col = start_col;
            // Le score de la colonne est le max de horizontal_count, vertical_count et diagonal_count
            unsigned score = MAX(horizontal_count, MAX(vertical_count, diagonal_count));
            moves_scores[col] = score;
            undo_move(grid, col);
        }
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
        // display_scores(moves_scores);
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