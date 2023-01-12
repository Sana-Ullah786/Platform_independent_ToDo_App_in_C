#ifndef GAME_H
#define GAME_H

/*
 * This printBoard Function prints the 3x3 Board on the terminal
 * Input: 3x3 Board
 * return : void
 */
void printBoard(int b[3][3]);

/*
 * This estimateBoard Function checks if the board is in wining position or not
 * Input: 3x3 Board
 * return : int
 */
int estimateBoard(int b[3][3]);

/*
 * This minimax Function calculates User score and computer score accordingly, and calculates teh best Moves for the Computer
 * Input: 3x3 Board
 * return : int
 */
int minimax(int b[3][3], int);

/*
    * This getMove Function get Inputs from user
    * Input: 3x3 Board
    * return : void
*/
void getMove(int b[3][3]);

/*
    * This myMain Function is the main function of the program
    * Input: void
    * return : void 
*/
void myMain();

#endif