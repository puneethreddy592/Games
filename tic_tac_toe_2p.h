#ifndef TIC_TAC_TOE_2P_H
#define TIC_TAC_TOE_2P_H

typedef struct {
    char name[20];
    char symbol;
    int score;
} Player;

void initialize_board();
void display_board();
int game_over();
void player_move(Player *player);
void tic_tac_toe_2p();

#endif /* TIC_TAC_TOE_2P_H */
