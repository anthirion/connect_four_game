#include "grid.h"
#include "constants.h"

/*
La grille est composée de 6 lignes et 7 colonnes. La case (0, 0) est en haut à gauche.
Chaque case de la grille peut contenir 3 valeurs possibles :
    - la valeur YELLOW_TOKEN indique qu'un jeton de couleur jaune est
    présent sur la case,
    - la valeur RED_TOKEN indique qu'un jeton de couleur rouge est
    présent sur la case,
    - la valeur NO_TOKEN indique qu'aucun jeton n'est présent sur la case.
*/

const int UP = -1;
const int DOWN = 1;


void init_grid(unsigned grid[6][7]) {
    /*
    Place des -1 dans toute la grille, indiquant l'absence de jetons
    */
   for (unsigned row = 0; row < N_ROWS; row++) {
		for (unsigned column = 0; column < N_COLUMNS; column++)
			grid[row][column] = NO_TOKEN;
   }
}

void display_line_numbers() {
	// Display the line numbers at the top and bottom of the grid
	printf(" ");
	for (unsigned row = 0; row < N_ROWS+1; row++)
		printf(" %u  ", row+1);
}

void display_grid(const unsigned grid[6][7]) {
	// Pattern séparant les lignes
	const char sep_pattern[] = "\n+---+---+---+---+---+---+---+\n";
	display_line_numbers();
	printf(sep_pattern);
	
	for (unsigned row = 0; row < N_ROWS; row++) {
		for (unsigned column = 0; column < N_COLUMNS; column++) {
			if (grid[row][column] == NO_TOKEN)
				printf("|   ");
			else if (grid[row][column] == YELLOW_TOKEN)
				printf("| O ");
			else if (grid[row][column] == RED_TOKEN)
				printf("| X ");
		}
		printf("|");
		printf(sep_pattern);
   }
	display_line_numbers();
	printf("\n\n");
}

unsigned play_token(unsigned grid[6][7], const int column, enum color token_color) {
    /*
    Place un jeton de la couleur {color} dans la colonne {column}.
    L'entier renvoyé indique si une erreur s'est produite ou non :
        - NO_ERROR => pas d'erreur
        - COLUMN_FULL => la colonne est pleine
        (la valeur des constantes est définie dans constants.c)
    On considère ici que le numéro de la colonne est valide, puisqu'il
    a déjà été vérifié dans une fonction du fichier interactions.c.
    On considère que la couleur du jeton ne peut pas être incorrecte
    car gérée par l'ordinateur et pas choisie par l'utilisateur (par
    défaut le joueur 1 se verra attribuée la couleur 0, jaune, et le
    joueur 2 la couleur 1, rouge).
    */
   	unsigned row = N_ROWS - 1;
	while (row != (unsigned)-1 && grid[row][column] != NO_TOKEN)
		row--;
	if (row == 0)
		return COLUMN_FULL;
	else
		grid[row][column] = ++token_color;
	return NO_ERROR;
}

unsigned checkVerticalWin(const unsigned grid[6][7]) {
	// Vérifier si 4 jetons sont alignés sur une ligne ou non
	// Comme la case (0,0) est en haut à gauche, il faut vérifier à partir
	// de la dernière ligne
	for (unsigned column = 0; column < N_COLUMNS; column++) {
		for (unsigned row = N_ROWS - 1; row >= 3 ; row--) { 
			if (grid[row][column] == YELLOW_TOKEN && grid[row-1][column] == YELLOW_TOKEN &&
				grid[row-2][column] == YELLOW_TOKEN && grid[row-3][column] == YELLOW_TOKEN)
				return PLAYER_1_WON;
			else if (grid[row][column] == RED_TOKEN && grid[row-1][column] == RED_TOKEN &&
					grid[row-2][column] == RED_TOKEN && grid[row-3][column] == RED_TOKEN)
				return PLAYER_2_WON;
		}
	}
	return GAME_CONTINUE;
}

unsigned checkHorizontalWin(const unsigned grid[6][7]) {
	// Vérifier si 4 jetons sont alignés sur une colonne ou non
	// Ici l'ordre des lignes n'est pas important
	for (unsigned row = N_ROWS - 1; row != (unsigned)-1; row--) {
		for (unsigned column = 0; column < N_COLUMNS - 3; column++) { 
			if (grid[row][column] == YELLOW_TOKEN && grid[row][column+1] == YELLOW_TOKEN &&
				grid[row][column+2] == YELLOW_TOKEN && grid[row][column+3] == YELLOW_TOKEN)
					return PLAYER_1_WON;
			else if (grid[row][column] == RED_TOKEN && grid[row][column+1] == RED_TOKEN &&
					grid[row][column+2] == RED_TOKEN && grid[row][column+3] == RED_TOKEN)
				return PLAYER_2_WON;
		}
	}
	return GAME_CONTINUE;
}

unsigned checkDiagonalWin(const unsigned grid[6][7], const unsigned row_start, const unsigned column_start, 
									const unsigned steps, const int way) {
	// Vérifier si 4 jetons sont alignés sur une diagonale ou non
	// La diagonale vérifiée commence à la ligne {row_start} et colonne {column_start}
	unsigned row = row_start;
	unsigned column = column_start;
	if (way == DOWN) {
		// Diagonales descendantes
		for (unsigned step=0; step < steps; step++) {
			if (grid[row][column] == YELLOW_TOKEN && grid[row+1][column+1] == YELLOW_TOKEN &&
				grid[row+2][column+2] == YELLOW_TOKEN && grid[row+3][column+3] == YELLOW_TOKEN)
				return PLAYER_1_WON;
			else if (grid[row][column] == RED_TOKEN && grid[row+1][column+1] == RED_TOKEN &&
				grid[row+2][column+2] == RED_TOKEN && grid[row+3][column+3] == RED_TOKEN)
				return PLAYER_2_WON;
			else {
				row++;
				column++;
			}
		}
	}
	else if (way == UP) {
		// Diagonales montantes
		for (unsigned step=0; step < steps; step++) {
			if (grid[row][column] == YELLOW_TOKEN && grid[row-1][column+1] == YELLOW_TOKEN &&
				grid[row-2][column+2] == YELLOW_TOKEN && grid[row-3][column+3] == YELLOW_TOKEN)
				return PLAYER_1_WON;
			else if (grid[row][column] == RED_TOKEN && grid[row-1][column+1] == RED_TOKEN &&
				grid[row-2][column+2] == RED_TOKEN && grid[row-3][column+3] == RED_TOKEN)
				return PLAYER_2_WON;
			else {
				row--;
				column++;
			}
		}
	}
	return GAME_CONTINUE;
}

unsigned check_game_status(unsigned grid[6][7]) {
    /*
    Vérifie si 4 jetons de la même couleur sont alignés ou si toute
    la grille est remplie (les 2 conditions d'arrêt du jeu) ou encore
    si un des 2 joueurs décide d'arrêter le jeu en tapant F.
    Valeur de retour :
        - GAME_CONTINUE : jeu non-terminé
        - PLAYER_1_WON : jeu terminé, le joueur 1 a gagné
        - PLAYER_2_WON : jeu terminé, le joueur 2 a gagné
        - GAME_INTERRUPTED_BY_PLAYER: jeu terminé par un des 2 joueurs
        (la valeur des constantes est définie dans constants.c)
    */
	unsigned game_status = checkHorizontalWin(grid);
	if (game_status != GAME_CONTINUE)
		return game_status;
	game_status = checkVerticalWin(grid);
	if (game_status != GAME_CONTINUE)
		return game_status;
	// Vérifier les diagonales descendantes
	unsigned steps = 1;
	for (unsigned column=3; column >= 1; column--) {
		game_status = checkDiagonalWin(grid, 0, column, steps, DOWN);
		if (game_status != GAME_CONTINUE)
			return game_status;
		++steps;
	}
	for (unsigned row=0; row <= 2; row++) {
		game_status = checkDiagonalWin(grid, row, 0, steps, DOWN);
		if (game_status != GAME_CONTINUE)
			return game_status;
		--steps;
	}
	// Vérifier les diagonales montantes
	for (unsigned row=3; row <= N_ROWS - 1; row++) {
		game_status = checkDiagonalWin(grid, row, 0, steps, UP);
		if (game_status != GAME_CONTINUE)
			return game_status;
		++steps;
	}
	for (unsigned column = 1; column <= 3; column++) {
		game_status = checkDiagonalWin(grid, N_ROWS - 1, column, steps, UP);
		if (game_status != GAME_CONTINUE)
			return game_status;
		--steps;
	}
	return GAME_CONTINUE;
}