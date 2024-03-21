#include "rock_paper_scissor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

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
