#include <iostream>
#include <stdlib.h>
#include "TicTacTow.h"
using namespace std;

int main()
{
    TicTacTow game; //the name of the object is game
    while(game.wanna_play_func()){
        game.initialize();
        while(!game.gameover()){
            game.display_board();
            game.player_turn();
        }
    }
    game.who_is_the_winner();
    system("pause");
    return 0;
}
