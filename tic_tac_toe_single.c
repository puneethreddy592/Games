/* tic_tac_toe_single.c */
#include "tic_tac_toe_single.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

char board[3][3];

void initialize_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void display_board() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int game_over() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return 1;
    }
    for (int i = 0; i < 3; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return 1;
    }
    if ((board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
        (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]))
        return 1;
    int draw = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                draw = 0;
                break;
            }
        }
        if (!draw) break;
    }
    if (draw) return -1;

    return 0;
}

void single_player_move(SinglePlayer *player) { // Renamed the function
    int row, col;
    printf("%s, enter your move (row and column): ", player->name);
    scanf("%d %d", &row, &col);
    usleep(1000000);
    system("cls");
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        display_board();
        printf("Invalid move. Try again.\n");
        single_player_move(player); // Renamed the function
    } else {
        board[row][col] = player->symbol;
    }
}

void computer_move(SinglePlayer *player) {
    int bestScore = -1000;
    int moveRow = -1, moveCol = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player->symbol;
                int score = minimax(0, 0, false, player->symbol == 'X' ? 'O' : 'X');
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    moveRow = i;
                    moveCol = j;
                }
            }
        }
    }

    board[moveRow][moveCol] = player->symbol;
}

int minimax(int depth, int isMaximizing, bool isMaximizerTurn, char aiSymbol) {
    int result = game_over();
    if (result != 0)
        return result;

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = aiSymbol;
                    int score = minimax(depth + 1, 0, !isMaximizerTurn, aiSymbol);
                    board[i][j] = ' ';
                    bestScore = score > bestScore ? score : bestScore;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = isMaximizerTurn ? 'X' : 'O';
                    int score = minimax(depth + 1, 1, !isMaximizerTurn, aiSymbol);
                    board[i][j] = ' ';
                    bestScore = score < bestScore ? score : bestScore;
                }
            }
        }
        return bestScore;
    }
}

void tic_tac_toe_single() {
    SinglePlayer players[2];
    int current_player = 1;
    int game_status = 0;
    char play_again;

    printf("Enter your name: ");
    scanf("%s", players[0].name);

    printf("%s, do you want to play as 'X' or 'O'? Enter your choice: ", players[0].name);
    char choice;
    scanf(" %c", &choice);
    choice = toupper(choice);
    if (choice != 'X' && choice != 'O') {
        printf("Invalid choice. Defaulting to 'X'.\n");
        choice = 'X';
    }
    players[0].symbol = choice;
    players[0].score = 0;

    char computerSymbol = (choice == 'X') ? 'O' : 'X';
    strcpy(players[1].name, "Computer");
    players[1].symbol = computerSymbol;
    players[1].score = 0;
    do {
    initialize_board();
    display_board();

    while (1) {
        if (current_player == 1)
            single_player_move(&players[0]);
        else
            computer_move(&players[1]);

        display_board();

        game_status = game_over();
        if (game_status == 1) {
            if (current_player == 1)
                printf("Player %s wins!\n", players[0].name);
            else
                printf("Computer wins!\n");
            players[current_player - 1].score++;
            break;
        } else if (game_status == -1) {
            printf("It's a draw!\n");
            break;
        }

        current_player = (current_player == 1) ? 2 : 1;
    }

    printf("Current score:\n");
    printf("%s: %d\n", players[0].name, players[0].score);
    printf("Computer: %d\n", players[1].score);

    printf("Do you want to play again? (Y/N): ");
    scanf(" %c", &play_again);

    } while (toupper(play_again) == 'Y');
}


