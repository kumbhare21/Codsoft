#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---------\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  // Rows
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {  // Columns
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||  // Diagonal 1
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {  // Diagonal 2
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to make a move
bool makeMove(char board[3][3], int row, int col, char player) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

// Function to switch players
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to reset the board for a new game
void resetBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameWon = false;
    bool playAgain = true;
    char choice;

    while (playAgain) {
        resetBoard(board);  // Initialize/reset the board for a new game
        gameWon = false;
        currentPlayer = 'X';  // Player X always starts first

        cout << "Welcome to Tic-Tac-Toe!" << endl;

        while (true) {
            displayBoard(board);
            int row, col;

            // Prompt the current player to make a move
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            // Adjust for zero-based index
            row--;
            col--;

            // Make the move if valid
            if (makeMove(board, row, col, currentPlayer)) {
                // Check if the current player has won
                if (checkWin(board, currentPlayer)) {
                    displayBoard(board);
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameWon = true;
                    break;
                }

                // Check if the game is a draw
                if (checkDraw(board)) {
                    displayBoard(board);
                    cout << "It's a draw!" << endl;
                    break;
                }

                // Switch players
                currentPlayer = switchPlayer(currentPlayer);
            } else {
                cout << "Invalid move! Try again." << endl;
            }
        }

        // Ask if the players want to play another game
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            playAgain = false;
        }
    }

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;
    return 0;
}
