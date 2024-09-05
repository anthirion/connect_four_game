const unsigned N_ROWS = 6;
const unsigned N_COLUMNS = 7;

// Constantes de la grille
const unsigned NO_TOKEN = 0;
const unsigned YELLOW_TOKEN = 1;
const unsigned RED_TOKEN = 2;

/*  La numérotation des codes est inspirée par celle des code HTTP */

// Tous les codes d'erreurs sont entre 10 et 19
const unsigned NO_ERROR = 10;
const unsigned COLUMN_FULL = 11;
const unsigned COLUMN_NUMBER_ERROR = 11;

// Tous les messages d'information sont entre 20 et 29
const unsigned GAME_CONTINUE = 20;
const unsigned PLAYER_1_WON = 21;
const unsigned PLAYER_2_WON = 22;

// Tous les messages d'information sur les tests sont entre 30 et 39
const unsigned TEST_PASSED = 30;
const unsigned TEST_FAILED = 31;

// Tous les messages d'information sur le fonctionnement de l'IA sont entre 40 et 49
const unsigned NO_WINNING_MOVE = 40;