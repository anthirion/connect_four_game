#ifndef GRID_H
#define GRID_H

#include <stdio.h>

enum color;

extern const int N_ROWS;
extern const int N_COLUMNS;

void init_grid(int grid[6][7]);
void display_grid(int grid[6][7]);
int play_token(int grid[6][7], int column, enum color);
int game_finished(int grid[6][7]);

#endif