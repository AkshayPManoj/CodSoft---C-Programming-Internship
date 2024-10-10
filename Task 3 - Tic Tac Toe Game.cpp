//Task 3 - Tic Tac Toe Game
#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime>   // For time()

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board; // 3x3 Tic-Tac-Toe board
    char currentPlayer; // Player 'X' starts the game

public:
    TicTacToe() {
        board.resize(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        srand(static_cast<unsigned>(time(0))); // Seed for random number generation
    }

    void play() {
        cout << "Welcome to Tic-Tac-Toe!" << endl;

        bool gameEnded = false;
        while (!gameEnded) {
            displayBoard();

            if (currentPlayer == 'X') {
                playerMove();
            } else {
                computerMove();
            }

            // Check if game is over
            if (isGameOver()) {
                gameEnded = true;
                displayBoard();
                if (currentPlayer == 'X') {
                    cout << "Congratulations! You win!" << endl;
                } else {
                    cout << "Computer wins! Better luck next time." << endl;
                }
            } else if (isBoardFull()) {
                gameEnded = true;
                displayBoard();
                cout << "It's a draw!" << endl;
            }

            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

private:
    void displayBoard() {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "| ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " | ";
            }
            cout << endl << "-------------" << endl;
        }
    }

    void playerMove() {
        bool validMove = false;
        while (!validMove) {
            int row, col;
            cout << "Enter your move (row[1-3] column[1-3]): ";
            cin >> row >> col;
            row--; col--; // Adjust for 0-indexing

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = currentPlayer;
                validMove = true;
            } else {
                cout << "Invalid move! Please try again." << endl;
            }
        }
    }

    void computerMove() {
        // Simple AI: Randomly choose an empty cell
        bool validMove = false;
        while (!validMove) {
            int row = rand() % 3;
            int col = rand() % 3;
            if (board[row][col] == ' ') {
                board[row][col] = currentPlayer;
                validMove = true;
            }
        }
        cout << "Computer played." << endl;
    }

    bool isGameOver() {
        return checkRows() || checkColumns() || checkDiagonals();
    }

    bool checkRows() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
                return true;
            }
        }
        return false;
    }

    bool checkColumns() {
        for (int j = 0; j < 3; ++j) {
            if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
                return true;
            }
        }
        return false;
    }

    bool checkDiagonals() {
        return (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
               (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ');
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
