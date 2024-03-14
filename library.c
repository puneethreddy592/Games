#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

char board[3][3];

void printRock() {
    printf("    ");
    printf("\033[37;100m"); printf("______\n"); printf("\033[0m");
    printf(" ");
    printf("\033[37;100m"); printf("__/ **** \\__\n"); printf("\033[0m");
    printf("\033[37;100m"); printf("|===*####*+++\\\n"); printf("\033[0m");
    printf("\033[37;100m"); printf("\\___****____|\n"); printf("\033[0m");
    printf("  ");
    printf("\033[37;100m"); printf("==\\______/\n"); printf("\033[0m");
}

void printPaper() {
    printf("\033[47m");
    printf(" ___________ \n");
    printf("|-----------|\n");
    printf("|-----------|\n");
    printf("|-----------|\n");
    printf("|-----------|\n");
    printf("|-----------|\n");
    printf("|-----------|\n");
    printf("|___________|\n"); printf("\033[0m");
}

void printScissor() {
    printf("   \\        /\n");
    printf("   \\\\      //\n");
    printf("    \\\\    //\n");
    printf("     \\\\  //\n");
    printf("      \\\\//\n");
    printf("       /\\ \n");
    printf("      //\\\\\n");
    printf("     //  \\\\     \n");
    printf("    //    \\\\ \n");
    printf("  (   )  (   ) \n");
    printf(" (___)    (___)   \n");
}

void printHand() {
    printf("    _______\n");
    printf("---'   ____)\n");
    printf("      (_____)\n");
    printf("      (_____)\n");
    printf("      (____)\n");
    printf("---.__(___)\n");
}

void printHand1(){
    printf("\n");
    printf("\n");
    printf("    _______\n");
    printf("---'   ____)\n");
    printf("      (_____)\n");
    printf("      (_____)\n");
    printf("      (____)\n");
    printf("---.__(___)\n");
}

void rockPaperScissor(){
    int ok = 1;
    struct GameState game;
    game.userScore = 0;
    game.compScore = 0;

    while (ok) {
        int validChoice = 0;
        while (!validChoice) {
            printf("Choose rock (r), paper (p), or scissor (s): ");
            scanf("%s", game.userChoice);
            if (strcmp(game.userChoice, "r") == 0 ||
                strcmp(game.userChoice, "p") == 0 ||
                strcmp(game.userChoice, "s") == 0) {
                validChoice = 1;
            } else {
                printf("Invalid input. Please enter 'r', 'p', or 's'.\n");
            }
        }
        int r = rand() % 3;
        if (r == 0) {
            strcpy(game.compChoice, "r");
        } else if (r == 1) {
            strcpy(game.compChoice, "p");
        } else {
            strcpy(game.compChoice, "s");
        }
        system("cls");
        printHand();
        usleep(500000);
        system("cls");
        printHand1();
        usleep(500000);
        system("cls");
        printHand();
        usleep(500000);
        system("cls");
        if (strcmp(game.compChoice, "r") == 0) {
            printRock();
        } else if (strcmp(game.compChoice, "p") == 0) {
            printPaper();
        } else if (strcmp(game.compChoice, "s") == 0) {
            printScissor();
        }
        if (strcmp(game.userChoice, game.compChoice) == 0) {
            printf("Oh!!! It's a tie.\n");
        } else if ((strcmp(game.userChoice, "r") == 0 && strcmp(game.compChoice, "p") == 0) ||
                   (strcmp(game.userChoice, "p") == 0 && strcmp(game.compChoice, "s") == 0) ||
                   (strcmp(game.userChoice, "s") == 0 && strcmp(game.compChoice, "r") == 0)) {
            printf("That's a win for me.\n");
            game.compScore++;
        } else {
            printf("You got this one.\n");
            game.userScore++;
        }

        sleep(2);
        printf("Wanna play again? (1 for Yes, 0 for No): ");
        scanf("%d", &ok);
        system("cls");
    }
    printf("\nIt is %d for you %d for me", game.userScore, game.compScore);
}



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
void player_move(Player *player) {
    int row, col;
    printf("%s, enter your move (row and column): ", player->name);
    scanf("%d %d", &row, &col);
    usleep(1000000);
    system("cls");
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        display_board();
        printf("Invalid move. Try again.\n");
        player_move(player);
    } else {
        board[row][col] = player->symbol;
    }
}
void tic_tac_toe(){
     Player players[2];
    int current_player = 1; 
    int game_status = 0;
    char play_again;
    for (int i = 0; i < 2; i++) {
        printf("Enter the name of Player %d: ", i+1);
        scanf("%s", players[i].name);
        char choice;
        if (i == 0) {
            printf("%s, do you want to play as 'X' or 'O'? Enter your choice: ", players[i].name);
            scanf(" %c", &choice);
            choice = toupper(choice);
        } else {
            choice = (players[0].symbol == 'X') ? 'O' : 'X';
            printf("%s, you have been assigned the symbol: %c\n", players[i].name, choice);
        }

        if (choice != 'X' && choice != 'O') {
            printf("Invalid choice. Defaulting to 'X'.\n");
            choice = 'X';
        }
        players[i].symbol = choice;
        players[i].score = 0;
    }

    do {
        initialize_board();
        display_board();
        while (1) {
            player_move(&players[current_player - 1]);
            display_board();

            game_status = game_over();
            if (game_status == 1) {
                printf("Player %s wins!\n", players[current_player - 1].name);
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
        printf("%s: %d\n", players[1].name, players[1].score);

        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &play_again);

    } while (toupper(play_again) == 'Y');
}