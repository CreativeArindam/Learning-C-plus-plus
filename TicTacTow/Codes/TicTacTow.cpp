#include <iostream>
#include <stdlib.h>
#include "TicTacTow.h"
using namespace std;

/** Initializes the board **/
void TicTacTow::initialize(){
    for(int i = 0; i < 9; i++){
            a[i] = 49+i; //using ASCII table
        }
}

/** Returns the player's current score **/
int TicTacTow::getscore(int player){
        if(player == 1){
            return p1score;
        }
        if(player == 2){
            return p2score;
        }
        cout << "~Invalid Player~";
        return (-1);
}

/** Increments the Player score after winning **/
void TicTacTow::incr_score(int player){
        if(player == 1){
            p1score++;
        }else if(player == 2){
            p2score++;
        }else cout << "~Invalid Player~";
}

/** Display the whole board **/
void TicTacTow::display_board(){
    system("cls"); //clears the screen
    cout << "\t\tW e l c o m e  t o  T i k T a k T o w  G a m e!" << endl;
    cout << "\t\t===============================================" << endl;
    cout << "\t\tPlayer1 [X]: " << getscore(1) << "\n\t\tPlayer2 [O]: " << getscore(2) << endl;
    cout << "\t\t\t\t     |     |     " << endl;
    cout << "\t\t\t\t  " << a[0] << "  |  " << a[1] << "  |  " << a[2] << "  " << endl;
    cout << "\t\t\t\t-----|-----|-----" << endl;
    cout << "\t\t\t\t  " << a[3] << "  |  " << a[4] << "  |  " << a[5] << "  " << endl;
    cout << "\t\t\t\t-----|-----|-----" << endl;
    cout << "\t\t\t\t  " << a[6] << "  |  " << a[7] << "  |  " << a[8] << "  " << endl;
    cout << "\t\t\t\t     |     |     " << endl;
}

bool TicTacTow::player_turn(){
    if(turn == 'X')
        cout << "Palyer1 [X] turn\nPlease enter the cell no: ";
    if(turn == 'O')
        cout << "Palyer2 [O] turn\nPlease enter the cell no: ";
    cin >> choice;
    if(a[choice-1] == 'X' || a[choice-1] == 'O')
        return false;
    switch(choice){
        case 1: a[0] = turn; break;
        case 2: a[1] = turn; break;
        case 3: a[2] = turn; break;
        case 4: a[3] = turn; break;
        case 5: a[4] = turn; break;
        case 6: a[5] = turn; break;
        case 7: a[6] = turn; break;
        case 8: a[7] = turn; break;
        case 9: a[8] = turn; break;
        default: return false;
    }
    if(turn == 'X')
        turn = 'O';
    else
        turn = 'X';
    return true;
}

/** Checks if the match is won or draw **/
bool TicTacTow::gameover(){
    if((a[0] == a[1] && a[0] == a[2]) ||
       (a[0] == a[3] && a[0] == a[6]) ||
       (a[3] == a[4] && a[3] == a[5]) ||
       (a[6] == a[7] && a[6] == a[8]) ||
       (a[1] == a[4] && a[1] == a[7]) ||
       (a[2] == a[5] && a[2] == a[8]) ||
       (a[0] == a[4] && a[0] == a[8]) ||
       (a[2] == a[4] && a[2] == a[6])){
            display_board();
            if(turn == 'O'){
                incr_score(1);
                cout << "Player1 [X] has won the match!";
            }else{
                incr_score(2);
                cout << "Player2 [O] has won the match!";
            }
            play_again();
            return true;
    }else{
        bool allFilled{true};
        for(int i = 0;i<9; i++){
            if(a[i] >= 49 && a[i] <= 57)
                allFilled = false;
        }
        if(allFilled){
            display_board();
            cout << "Match draw";
            play_again();
            return true;
        }
        return false;
    }
}

/** Asks the player if they want to play again**/
void TicTacTow::play_again(){
        char choice{'x'};
        cout << "\nPress any key to play again. Press 'Q' to quit ";
        cin >> choice;
        if(choice == 'q' || choice == 'Q'){
            wanna_play = false;
        }
}

/** Finds the winner of the entire game **/
void TicTacTow::who_is_the_winner(){
    system("cls"); // clears the screen
    cout << "===============================================================" << endl;
    if(p1score > p2score){
        cout << "\t\t Player1 [X]  i s  t h e  w i n n e r !" << endl;
    }else if(p1score < p2score){
        cout << "\t\t Player1 [X]  i s  t h e  w i n n e r !" << endl;
    }else{
        cout << "\t\t M a t c h  D r a w!" << endl;
    }
    cout << "\t\t\tPlayer1 [X]: " << getscore(1) << "  Player2 [O]: " << getscore(2) << endl;
    cout << "===============================================================" << endl;
}
