#ifndef _TICTACTOW_H_
#define _TICTACTOW_H_

#include <iostream>
#include <stdlib.h>

using namespace std;

class TicTacTow{
    int choice{0},p1score{0},p2score{0};
    char a[9]; //board
    char turn ; //defines whose turn
    bool wanna_play{true}; //for play again
public:
    void display_board();
    bool player_turn();
    int getscore(int player);
    void incr_score(int player);
    bool gameover();
    void play_again();
    void initialize();
    bool wanna_play_func(){ return wanna_play;}
    void who_is_the_winner();

    /** Constructor **/
    TicTacTow(){
        for(int i = 0; i < 9; i++){
            a[i] = 49+i; // using ASCII table
        }
        turn = 'X';
    }
};

#endif // _TICTACTOW_H_
