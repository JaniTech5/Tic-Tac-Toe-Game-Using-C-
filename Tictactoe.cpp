#include <iostream>

using namespace std;

class TicTacToe {
public:
    TicTacToe();
    void playGame();

private:
    char board[3][3];
    char currentPlayer;

    void displayBoard();
    bool makeMove(int row, int col);
    bool checkWin();
    bool checkDraw();
    void switchPlayer();
};

TicTacToe::TicTacToe() : currentPlayer('X') {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void TicTacToe::playGame() {
    while (true) {
        displayBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";

        while (true) {
            cin >> row >> col;
            if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && makeMove(row - 1, col - 1)) {
                break;
            } else {
                cout << "Invalid move. Try again: ";
            }
        }

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        switchPlayer();
    }
}

void TicTacToe::displayBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "--+---+--\n";
    }
    cout << "\n";
}

bool TicTacToe::makeMove(int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool TicTacToe::checkWin() {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

bool TicTacToe::checkDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
