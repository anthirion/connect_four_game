#ifndef COMPUTER_H
#define COMPUTER_H

#include <stdlib.h>
#include "constants.h"
#include "grid.h"

void undo_move(unsigned short grid[][N_COLUMNS], const unsigned short column);
unsigned short check_winning_move(unsigned short grid[][N_COLUMNS]);
void compute_column_scores(unsigned short grid[][N_COLUMNS]);
unsigned short play(unsigned short grid[][N_COLUMNS]);

#endif