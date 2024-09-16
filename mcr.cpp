#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isWin(char game[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if ((game[i][0] == game[i][1] && game[i][1] == game[i][2]) && (game[i][0] == 'X' || game[i][0] == 'O')) {
            return true;
        }
        if ((game[0][i] == game[1][i] && game[1][i] == game[2][i]) && (game[0][i] == 'X' || game[0][i] == 'O')) {
            return true;
        }
    }
    if ((game[0][0] == game[1][1] && game[1][1] == game[2][2]) && (game[0][0] == 'X' || game[0][0] == 'O')) {
        return true;
    }
    if ((game[0][2] == game[1][1] && game[1][1] == game[2][0]) && (game[0][2] == 'X' || game[0][2] == 'O')) {
        return true;
    }
    return false;
}

int main() {
    char game[3][3] = {{' ', ' ', ' '},
                       {' ', ' ', ' '},
                       {' ', ' ', ' '}};
    char player1 = 'X';
    char player2 = 'O';
    bool turn = true; // false for player 1's turn, true for player 2's turn. Player 1 first.
    cout << "X = Player 1" << endl << "O = Player 2" << endl;

    for (int n = 0; n < 9; n++) {
        turn = !turn; // use the not-operator to change true to false or false to true.
        if (turn == false)
            cout << "Player 1: ";
        else
            cout << "Player 2: ";

        int i, j;
        while (true) {
            cout << "Which cell to mark? i:[1..3], j:[1..3]: ";
            cin >> i >> j;
            if (cin.fail() || i < 1 || i > 3 || j < 1 || j > 3 || game[i - 1][j - 1] != ' ') {
                cout << "Invalid input! Please enter again." << endl;
                cin.clear();
            } else {
                break;
            }
        }

        if (turn == false)
            game[i - 1][j - 1] = 'X';
        else
            game[i - 1][j - 1] = 'O';

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << game[i][j] << " ";
            }
            cout << endl;
        }

        if (isWin(game)) {
            if (n % 2 == 0)
                cout << "Player 1 wins!" << endl;
            else
                cout << "Player 2 wins!" << endl;
            //cout << "Win!" << endl;
            break;
        }
    }

    bool tie = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (game[i][j] == ' ') {
                tie = false;
                break;
            }
        }
        if (!tie) break;
    }
    if (tie)
        cout << "Tie!" << endl;

    // show the game to console
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << game[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
