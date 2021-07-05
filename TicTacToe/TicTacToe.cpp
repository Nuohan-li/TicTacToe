// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


using namespace std;

void game_board(char tiles[9]) {
   
    cout << "\n\n             Tic Tac Toe\n\n" << endl;
    cout << "player 1 - (X)           player 2 - (O)" << endl;
    cout << endl;
    cout << "             " << tiles[0] << "  |  " << tiles[1] << "  |  " << tiles[2] << endl;
    cout << "           -----|-----|-----" << endl;
    cout << "             " << tiles[3] << "  |  " << tiles[4] << "  |  " << tiles[5] << endl;
    cout << "           -----|-----|-----" << endl;
    cout << "             " << tiles[6] << "  |  " << tiles[7] << "  |  " << tiles[8] << endl;
}

// 1 = win, 0 = game in progress, -1 = draw
int win_condition(char tiles[9]) {
    if (tiles[0] == tiles[1] && tiles[1] == tiles[2])
        return 1;
    else if (tiles[3] == tiles[4] && tiles[4] == tiles[5])
        return 1;
    else if (tiles[6] == tiles[7] && tiles[7] == tiles[8])
        return 1;
    else if (tiles[0] == tiles[3] && tiles[3] == tiles[6])
        return 1;
    else if (tiles[1] == tiles[4] && tiles[4] == tiles[7])
        return 1;
    else if (tiles[2] == tiles[5] && tiles[5] == tiles[8])
        return 1;
    else if (tiles[0] == tiles[4] && tiles[4] == tiles[8])
        return 1;
    else if (tiles[2] == tiles[4] && tiles[4] == tiles[6])
        return 1;
    else if (tiles[0] != 1 && tiles[1] != 2 && tiles[2] != 3 &&
        tiles[3] != 4 && tiles[4] != 5 && tiles[5] != 6 &&
        tiles[6] != 7 && tiles[7] != 8 && tiles[8] != 9)
        return 0;
    else
        return -1;
}

void game() {

    char tiles[9]{ '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int position{0};
    int player_turn = 1;
    game_board(tiles);

    /*
    * 1. decide whose turn it is
      2. asking input from user
      3. check if input is valid
      4. update the board
      5. check if an user wins 
      6. repeat 
    */

    do {
        if (player_turn % 2 == 1) {
            cout << "Player 1: " << endl;
            cin >> position;
            if (position == tiles[position - 1] - '0') {
                tiles[position - 1] = 'x';
                system("cls");
                game_board(tiles);
                player_turn++;
            }
            else {
                cin.clear();
                cin.ignore();
                cout << "invalid" << endl;
                continue;
            }
        }
        else {
            cout << "Player 2: " << endl;
            cin >> position;
            if (position == tiles[position - 1] - '0') {
                tiles[position - 1] = 'o';
                system("cls");
                game_board(tiles);
                player_turn++;
            }
            else {
                cin.clear();
                cin.ignore();
                cout << "invalid" << endl;
                continue;
            }

        }

    } while (win_condition(tiles) == 0);
}

int main(){
    game();
}

