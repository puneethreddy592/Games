#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

struct GameState {
    char userChoice[10];
    char compChoice[10];
    int userScore;
    int compScore;
};

void printRock();
void printPaper();
void printScissor();
void printHand();
void printHand1();
void rockPaperScissor();

typedef struct {
    char name[20];
    char symbol;
    int score;
} Player;

extern char board[3][3]; // Declaration of the board as an external variable

void initialize_board();
void display_board();
int game_over();
void player_move(Player *player);
void tic_tac_toe();

#endif /* LIBRARY_H */
