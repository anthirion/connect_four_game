const unsigned short N_ROWS = 6;
const unsigned short N_COLUMNS = 7;

// Constantes de la grille
const unsigned short NO_TOKEN = 0;
const unsigned short YELLOW_TOKEN = 1;
const unsigned short RED_TOKEN = 2;

/*  La numérotation des codes est inspirée par celle des code HTTP */

// Tous les codes d'erreurs sont entre 10 et 19
const unsigned short NO_ERROR = 10;
const unsigned short COLUMN_FULL = 11;
const unsigned short COLUMN_NUMBER_ERROR = 11;

// Tous les messages d'information sont entre 20 et 29
const unsigned short GAME_CONTINUE = 20;
const unsigned short PLAYER_1_WON = 21;
const unsigned short PLAYER_2_WON = 22;

// Tous les messages d'information sur les tests sont entre 30 et 39
const unsigned short TEST_PASSED = 30;
const unsigned short TEST_FAILED = 31;

// Tous les messages d'information sur le fonctionnement de l'IA sont entre 40 et 49
const unsigned short NO_WINNING_MOVE = 40;