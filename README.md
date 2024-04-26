🎮 Welcome to our gaming repository! 🎮

This repository is home to some classic games for you to enjoy. Let's take a quick look at what's available:

Tic-Tac-Toe Single Player:
Challenge yourself against the computer in this classic game of Tic-Tac-Toe. Can you outsmart the AI? 💻🤖

Rock-Paper-Scissors:
Test your luck and strategy in this timeless game of Rock-Paper-Scissors. Will you emerge as the champion? 🗿📄✂️

Connect Four:
Strategize and outmaneuver your opponent in this engaging game of Connect Four. Can you be the first to connect four dots? 🔴🟡🔴🟡

Feel free to explore the source code, customize the games, and even contribute improvements! 🛠️ To get started and run these games:
<br><br><br><br><br><br><br><br><br>One can download the files and make necessary changes before commiting any get approval. <br>
To run the below files go to main.c <br>
if u want to run tic_tac_toe_single player use <br> gcc -o main main.c tic_tac_toe_single.c <br>and then main.exe will be created and run that using <br>./main <br>
***************To make a master command********************
gcc -c rock_paper_scissor .c -o rock_paper_scissor .o<br>
ar rcs rock_paper_scissor .a rock_paper_scissor .o<br>
mv rock_paper_scissor.a librock_paper_scissor.a<br>
do same for other files<br>
gcc main.c -o main -L. -lrock_paper_scissor -ltic_tac_toe_2p -ltic_tac_toe_single -lc42p

