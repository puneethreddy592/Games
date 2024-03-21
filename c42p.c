#include "c42p.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
//#include<unistd.h>
#include<stdbool.h>

void endtimer() {
    char time[] = "######";
    printf("%s", time);
    for(int i = 0; i < 6; i++) {
        printf("\b \b");
        fflush(stdout);
        Sleep(1);
    }
    printf("\n");
}

int win(char A[10][10], char c1, char c2) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 7; j++) {
            if(A[i][j] == c1 && A[i][j+1] == c1 && A[i][j+2] == c1 && A[i][j+3] == c1) return 1;
        }
    }

    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 10; j++) {
            if(A[i][j] == c1 && A[i+1][j] == c1 && A[i+2][j] == c1 && A[i+3][j] == c1) return 1;
        }
    }

    for(int i = 3; i < 10; i++) {
        for(int j = 0; j < 7; j++) {
            if(A[i][j] == c1 && A[i-1][j+1] == c1 && A[i-2][j+2] == c1 && A[i-3][j+3] == c1) return 1;
        }
    }

    for(int i = 3; i < 10; i++) {
        for(int j = 9; j >= 3; j--) {
            if(A[i][j] == c1 && A[i-1][j-1] == c1 && A[i-2][j-2] == c1 && A[i-3][j-3] == c1) return 1;
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 7; j++) {
            if(A[i][j] == c2 && A[i][j+1] == c2 && A[i][j+2] == c2 && A[i][j+3] == c2) return 2;
        }
    }

    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 10; j++) {
            if(A[i][j] == c2 && A[i+1][j] == c2 && A[i+2][j] == c2 && A[i+3][j] == c2) return 2;
        }
    }

    for(int i = 3; i < 10; i++) {
        for(int j = 0; j < 7; j++) {
            if(A[i][j] == c2 && A[i-1][j+1] == c2 && A[i-2][j+2] == c2 && A[i-3][j+3] == c2) return 2;
        }
    }

    for(int i = 3; i < 10; i++) {
        for(int j = 9; j >= 3; j--) {
            if(A[i][j] == c2 && A[i-1][j-1] == c2 && A[i-2][j-2] == c2 && A[i-3][j-3] == c2) return 2;
        }
    }

    return 0;
}
void c42p(){
    char p1[100], p2[100], c1, c2;
    char replay = 'y';
    int w1 = 0, w2 = 0, gamecount = 0, tiecount = 0;

    printf("Enter player 1 Name and character: ");
    scanf("%s %c", p1, &c1);
    printf("Enter player 2 Name and character: ");
    scanf("%s %c", p2, &c2);

    while(replay == 'y' || replay == 'Y') {
        system("cls");
        printf("Player 1: %s v/s Player 2: %s\n", p1, p2);
        for(int i = 0; i < 10; i++)
            printf("%d ", i);
        printf("\n");

        char A[10][10];
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                A[i][j] = '.';
        
        for(int l = 0; l < 10; l++) {
            for(int m = 0; m < 10; m++)
            printf("%c ", A[l][m]);
            printf("\n");
        }
        for(int i = 0; i < 50; i++) {
            int winner = win(A, c1, c2);
            bool p1f = 1;
            bool t = 1;

            while(p1f) {
                int a;
                char aa;
                t = 1;
                while(t) {
                    printf("\nEnter your choice player 1: ");
                    scanf(" %c", &aa);
                    if(!(aa>= '0' && aa <= '9' )) {
                        system("cls");
                        printf("Player 1: %s v/s Player 2: %s\n", p1, p2);
                        for(int o = 0; o < 10; o++)
                            printf("%d ", o);
                        printf("\n");
                        for(int l = 0; l < 10; l++) {
                            for(int m = 0; m < 10; m++)
                                printf("%c ", A[l][m]);
                            printf("\n");
                        }
                        printf("\nNot a valid choice.\n");
                    } else
                        t = 0;
                }
                printf("\n");
                a=aa-'0';

                bool columnAvailable = 0;
                for(int k = 9; k >= 0; k--) {
                    if(A[k][a] == '.') {
                        A[k][a] = c1;
                        p1f = 0;
                        columnAvailable = 1;
                        break;
                    }
                }
                if(!columnAvailable) {
                    system("cls");
                    printf("Player 1: %s v/s Player 2: %s\n", p1, p2);
                    for(int o = 0; o < 10; o++)
                        printf("%d ", o);
                    printf("\n");
                    for(int l = 0; l < 10; l++) {
                        for(int m = 0; m < 10; m++)
                            printf("%c ", A[l][m]);
                        printf("\n");
                    }
                    printf("\nNot a valid choice.\n");
                }
            }

            system("cls");
            printf("Player 1: %s v/s Player 2: %s\n", p1, p2);
            for(int o = 0; o < 10; o++)
                printf("%d ", o);
            printf("\n");
            for(int l = 0; l < 10; l++) {
                for(int m = 0; m < 10; m++)
                    printf("%c ", A[l][m]);
                printf("\n");
            }

            winner = win(A, c1, c2);

            if(winner == 1) {
                printf("Player 1 wins.\n");
                w1++; gamecount++;
                printf("Do you want to play again? \n Yes(Y) or No(N): ");
                scanf(" %c", &replay);
                break;
            } else if(winner == 2) {
                printf("Player 2 wins.\n");
                w2++; gamecount++;
                printf("Do you want to play again? \n Yes(Y) or No(N): ");
                scanf(" %c", &replay);
                break;
            }

            bool p2f = 1;
            bool f = 1;

            while(p2f) {
                int b;
                char bb;
                f = 1;
                while(f) {
                    printf("\nEnter your choice player 2: ");
                    scanf(" %c", &bb);
                    if(!(bb >= '0' && bb <= '9' )) {
                        system("cls");
                        printf("Player 1: %s v/s Player 2: %s\n", p1, p2);
                        for(int o = 0; o < 10; o++)
                            printf("%d ", o);
                        printf("\n");
                        for(int l = 0; l < 10; l++) {
                            for(int m = 0; m < 10; m++)
                                printf("%c ", A[l][m]);
                            printf("\n");
                        }
                        printf("\nNot a valid choice.\n");
                    } else
                        f = 0;
                }
                printf("\n");
                b=bb-'0';

                bool columnAvailable = 0;
                for(int k = 9; k >= 0; k--) {
                    if(A[k][b] == '.') {
                        A[k][b] = c2;
                        p2f = 0;
                        columnAvailable = 1;
                        break;
                    }
                }
                if(!columnAvailable) {
                    system("cls");
                    printf("Player 1: %s v/s Player 2: %s\n", p1, p2);
                    for(int o = 0; o < 10; o++)
                        printf("%d ", o);
                    printf("\n");
                    for(int l = 0; l < 10; l++) {
                        for(int m = 0; m < 10; m++)
                            printf("%c ", A[l][m]);
                        printf("\n");
                    }
                    printf("\nNot a valid choice.\n");
                }
            }

            system("cls");
            printf("Player 1: %s v/s Player 2: %s\n", p1, p2);
            for(int o = 0; o < 10; o++)
                printf("%d ", o);
            printf("\n");
            for(int l = 0; l < 10; l++) {
                for(int m = 0; m < 10; m++)
                    printf("%c ", A[l][m]);
                printf("\n");
            }

            winner = win(A, c1, c2);

            if(winner == 1) {
                printf("Player 1 wins.\n");
                w1++; gamecount++;
                printf("Do you want to play again? \n Yes(Y) or No(N): ");
                scanf(" %c", &replay);
                break;
            } else if(winner == 2) {
                printf("Player 2 wins.\n");
                w2++; gamecount++;
                printf("Do you want to play again? \n Yes(Y) or No(N): ");
                scanf(" %c", &replay);
                break;
            }

            if(i == 49) {
                printf("\nNobody Wins!! It's a tie.\n");
                tiecount++; gamecount++;
                printf("Do you want to play again? \n Yes(Y) or No(N): ");
                scanf(" %c", &replay);
            }
        }
    }

    printf("Score of Player1: %d\nScore of Player2:  %d\nTie Count: %d\nTotal Games Played: %d\n", w1, w2, tiecount, gamecount);
    endtimer();
}