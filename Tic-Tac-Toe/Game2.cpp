#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char currentPlayer = 'X';

// Function to display the Tic-Tac-Toe board
void displayBoard() {
    cout << "  1   2   3" << endl;
    for (int row = 0; row < 3; row++) {
        cout << " ";
        for (int col = 0; col < 3; col++) {
            cout << board[row][col];
            if (col < 2)
                cout << " | ";
        }
        cout << endl;
        if (row < 2)
            cout << " ---|---|---" << endl;
    }
    cout << endl;
}


bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true; // Horizontal win
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true; // Vertical win
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true; // Diagonal win
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true; // Diagonal win

    return false;
}


bool checkDraw() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == ' ')
                return false; 
        }
    }
    return true; 
}


void switchPlayer() {
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main() {
    bool gameOver = false;

    while (!gameOver) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        int row, col;
        cin >> row >> col;

        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = currentPlayer;

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!" << endl;
                gameOver = true;
            } else {
                switchPlayer();
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    char playAgain;
    cout << "Play again? (Y/N): ";
    cin >> playAgain;

    if (playAgain == 'Y' || playAgain == 'y') {
   
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';
        gameOver = false;
    }

    return 0;
}
