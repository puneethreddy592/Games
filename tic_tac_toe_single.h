#ifndef TIC_TAC_TOE_SINGLE_H
#define TIC_TAC_TOE_SINGLE_H

#include <stdbool.h>

typedef struct {
    char name[20];
    char symbol;
    int score;
} SinglePlayer;

extern char board[3][3];

void initialize_board();
void display_board();
int game_over();
void single_player_move(SinglePlayer *player); 
void computer_move(SinglePlayer *player);
int minimax(int depth, int isMaximizing, bool isMaximizerTurn, char aiSymbol);
void tic_tac_toe_single();

#endif /* TIC_TAC_TOE_SINGLE_H */
