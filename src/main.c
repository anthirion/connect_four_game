#include <stdlib.h>
#include <stdio.h>

#include "grid.h"
#include "winning_combinations.h"

// unsigned check_game_continues(const unsigned error, const unsigned game_status) {
//     if (error != NO_ERROR)   return error;
//     if (game_status != GAME_CONTINUE)   return game_status;
//     return 0;
// }

int main() {
    // For test purposes
    unsigned test_result;
    test_result = check_winning_combinations();
    if (test_result != TEST_PASSED)
        return EXIT_FAILURE;
    
    return EXIT_SUCCESS;
}