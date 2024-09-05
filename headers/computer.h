#ifndef COMPUTER_H
#define COMPUTER_H

#include <stdlib.h>
#include "constants.h"
#include "grid.h"

void undo_move(unsigned grid[6][7], const unsigned column);
unsigned check_winning_move(unsigned grid[6][7]);
void compute_column_scores(unsigned grid[6][7]);
unsigned play(unsigned grid[6][7]);

#endif