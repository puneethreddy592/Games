#ifndef ROCK_PAPER_SCISSOR_H
#define ROCK_PAPER_SCISSOR_H

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

#endif /* ROCK_PAPER_SCISSOR_H */
