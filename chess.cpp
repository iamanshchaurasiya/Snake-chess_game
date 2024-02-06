#include <iostream>
#include <vector>

using namespace std;
char board[8][8] = {                                // Define the chessboard as an 8x8 grid
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};
void displayBoard() {                               // Function to display the chessboard
    cout << "  a b c d e f g h" << endl;
    for (int i = 0; i < 8; i++) {
        cout << 8 - i << " ";
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
pair<int, int> convertMove(string move) {           // Function to convert algebraic notation to array indices
    int col = move[0] - 'a';
    int row = 8 - (move[1] - '0');
    return make_pair(row, col);
}
bool isValidMove(pair<int, int> from, pair<int, int> to) {  // Function to check if a move is valid
    if (from.first < 0 || from.first > 7 || from.second < 0 || from.second > 7 ||   // Check if the 'from' and 'to' positions are within the board boundaries
        to.first < 0 || to.first > 7 || to.second < 0 || to.second > 7) {
        return false;
    }
    return true;
}
int main() {
    string move;
    pair<int, int> from, to;
    displayBoard();                     // Display initial chessboard
    while (true) {                      // Game loop
        cout << "Enter your move (e.g., e2-e4): ";
        cin >> move;
        from = convertMove(move.substr(0, 2));      // Convert algebraic notation to array indices
        to = convertMove(move.substr(3, 2));
        if (!isValidMove(from, to)) {                       // Check if move is valid
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        board[to.first][to.second] = board[from.first][from.second];    // Update chessboard with move
        board[from.first][from.second] = ' '; // Clear the 'from' position
        displayBoard();                        // Display updated chessboard

        // Check for game end conditions (checkmate, stalemate, etc.) Implement game end conditions here
        // For simplicity, the game loop continues indefinitely until manually stopped
    }
    
    return 0;
}
