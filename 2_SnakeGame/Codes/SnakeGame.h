#ifndef _SNAKEGAME_H_
#define _SNAKEGAME_H_
#include <iostream>
#include <stdlib.h>
namespace keys{
    enum direction{STOP,LEFT,RIGHT,UP,DOWN};
}

using namespace std;

class SnakeGame{
    const int width{60}, height{20};
    keys::direction dir;
    int x{width/2}, y{height/2}, fruitX, fruitY,score{0};
    int tailX[100],tailY[100],nTail{0};
    bool gameOver{false};
public:
    bool game_over(){return gameOver;}
    void draw();
    void input();
    void logic();

    /** Constructor */
    SnakeGame() : fruitX{rand() % width},fruitY{rand() % height}{
        dir = keys::STOP;
    }
};


#endif // _SNAKEGAME_H_
