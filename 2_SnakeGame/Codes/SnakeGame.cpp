#include <stdio.h>
#include <conio.h>
#include "SnakeGame.h"

using namespace std;

void SnakeGame::draw(){
    system("cls");
    cout << "Score: " << score << endl;
    for(int i=0;i<width;i++){
        cout << "#";
    }
    cout << endl;

    for(int i=0; i<height; i++){
        for(int j =0; j<width; j++){
            if(j == 0 || j == width - 1)
                cout << "#";
            else{
                if(j == fruitX && i == fruitY)
                    cout << "F";
                else if(j == x && i == y)
                    cout << "O";
                else{
                    bool printed{false};
                    for(int k = 0;k<nTail; k++){
                        if(i == tailY[k] && j== tailX[k]){
                            cout << "o";
                            printed = true;
                        }
                    }
                    if(!printed)
                        cout << " ";
                }
            }
        }
        cout << endl;
    }

    for(int i=0;i<width;i++){
        cout << "#";
    }
    cout << endl;
}

void SnakeGame::input(){
    if(_kbhit()){
        switch(_getch()){
        case 'i':
        case 'I': dir = keys::UP; break;
        case 'k':
        case 'K': dir = keys::DOWN; break;
        case 'j':
        case 'J': dir = keys::LEFT; break;
        case 'l':
        case 'L': dir = keys::RIGHT; break;
        case 'x':
        case 'X': dir = keys::STOP; break;
        default: break;
        }
    }
}

void SnakeGame::logic(){
    int prevX{tailX[0]}, prevY{tailY[0]};
    int prev2X,prev2Y;
    tailX[0] = x; tailY[0] = y;
    for(int i=1; i<nTail; i++){
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(dir){
    case keys::UP: y--; break;
    case keys::DOWN: y++; break;
    case keys::LEFT: x--; break;
    case keys::RIGHT: x++; break;
    default: break;
    }

    if(x == 0 || x == width-1 || y == -1 || y == height){
        gameOver = true;
    }
    for(int i=0; i<nTail; i++){
        if(x == tailX[i] && y == tailY[i])
            gameOver = true;
    }

    if(x == fruitX && y == fruitY){
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail ++;
        score +=10;
    }
}
