#ifndef GRID_H
#define GRID_H

#include <stdio.h>

#include "constants.h"

enum color;

void init_grid(unsigned short grid[][N_COLUMNS]);
void display_grid(const unsigned short grid[][N_COLUMNS]);
unsigned short play_token(unsigned short grid[][N_COLUMNS], const int max_score_column, enum color color);
unsigned short check_game_status(unsigned short grid[][N_COLUMNS]);

#endif