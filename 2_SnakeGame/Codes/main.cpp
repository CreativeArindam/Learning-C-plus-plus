#include <iostream>
#include <stdlib.h>
#include "SnakeGame.h"
using namespace std;

int main()
{
    SnakeGame game;
    while(!game.game_over()){
        game.draw();
        game.input();
        game.logic();
    }
    cout << "Game Over!!!" << endl;
    system("pause");
    return 0;
}
