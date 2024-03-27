One can download the files and make necessary changes before commiting any get approval. <br>
To run the below files go to main.c <br>
if u want to run tic_tac_toe_single player use <br> gcc -o main main.c tic_tac_toe_single.c <br>and then main.exe will be created and run that using <br>./main <br>
***************To make a master command********************
gcc -c rock_paper_scissor .c -o rock_paper_scissor .o<br>
ar rcs rock_paper_scissor .a rock_paper_scissor .o<br>
mv rock_paper_scissor.a librock_paper_scissor.a<br>
do same for other files<br>
gcc main.c -o main -L. -lrock_paper_scissor -ltic_tac_toe_2p -ltic_tac_toe_single -lc42p

