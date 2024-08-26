const int N_ROWS = 6;
const int N_COLUMNS = 7;

// Constantes de la grille
const NO_TOKEN = -1;
const YELLOW_TOKEN = 1;
const RED_TOKEN = 2;

/*  La numérotation des codes est inspirée par celle des code HTTP */

// Tous les codes d'erreurs sont entre 10 et 20
const int NO_ERROR = 10;
const int COLUMN_FULL = 11;
const int COLUMN_NUMBER_ERROR = 12;

// Tous les messages d'information sont entre 20 et 30
const int GAME_CONTINUE = 20;
const int PLAYER_1_WON = 21;
const int PLAYER_2_WON = 22;
const int GAME_INTERRUPTED_BY_PLAYER = 23;