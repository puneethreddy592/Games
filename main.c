#include "rock_paper_scissor.h"
#include "tic_tac_toe_2p.h"
#include "c42p.h"
#include "tic_tac_toe_single.h"
#include <stdio.h>
//***************To make a master command********************
// gcc -c library1.c -o library1.o
// ar rcs liblibrary1.a library1.o
// mv rock_paper_scissor.a librock_paper_scissor.a
// gcc main.c -o main -L. -lrock_paper_scissor -ltic_tac_toe_2p -ltic_tac_toe_single -lc42p

int main() {
    c42p();
    return 0;
}
