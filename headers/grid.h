#ifndef GRID_H
#define GRID_H

#include <stdio.h>

#include "constants.h"

enum color;

void init_grid(unsigned grid[6][7]);
void display_grid(const unsigned grid[6][7]);
unsigned play_token(unsigned grid[6][7], const int, enum color);
unsigned check_game_status(unsigned grid[6][7]);

#endif