#include <iostream> 
using namespace std; 

// 2D array to represent the Tic-Tac-Toe board
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row; // Variable to store the row index of the player's move
int column; // Variable to store the column index of the player's move
char token = 'x'; // Variable to keep track of whose turn it is ('x' for player 1, '0' for player 2)
bool tie = false; // Variable to check if the game is a tie
string n1 = ""; // Variable to store the name of player 1
string n2 = ""; // Variable to store the name of player 2
char lastToken; // Variable to keep track of the last player who made a move

// Function to display the current state of the board
void functionOne() {
    cout << "     |     |     \n"; // Print top border
    cout << "  " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "  \n"; // Print first row
    cout << "_____|_____|_____\n"; // Print horizontal separator
    cout << "     |     |     \n"; // Print middle border
    cout << "  " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "  \n"; // Print second row
    cout << "_____|_____|_____\n"; // Print horizontal separator
    cout << "     |     |     \n"; // Print bottom border
    cout << "  " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "  \n"; // Print third row
    cout << "     |     |     \n"; // Print bottom border
}

// Function to handle player input and update the board
void functionTwo() {
    int digit; // Variable to store the player's input

    while (true) { // Loop until a valid move is made
        // Prompt the current player for input
        if (token == 'x') {
            cout << n1 << ", please enter a number (1-9): "; // Player 1's turn
        } else {
            cout << n2 << ", please enter a number (1-9): "; // Player 2's turn
        }
        cin >> digit; // Read the player's input

        // Validate the input
        if (digit < 1 || digit > 9) {
            cout << "Invalid input! Please enter a number between 1 and 9." << endl; // Error message
            continue; // Ask for input again
        }

        // Map the input number to the corresponding row and column in the board
        switch (digit) {
            case 1: row = 0; column = 0; break;
            case 2: row = 0; column = 1; break;
            case 3: row = 0; column = 2; break;
            case 4: row = 1; column = 0; break;
            case 5: row = 1; column = 1; break;
            case 6: row = 1; column = 2; break;
            case 7: row = 2; column = 0; break;
            case 8: row = 2; column = 1; break;
            case 9: row = 2; column = 2; break;
        }
        // Check if the chosen space is already occupied
        if (space[row][column] != 'x' && space[row][column] != '0') {
            space[row][column] = token; // Place the token on the board
            lastToken = token; // Update lastToken to the current player's token
            token = (token == 'x') ? '0' : 'x'; // Switch token for the next player
            functionOne(); // Display the board after the move
            break; 
        } else {
            cout << "There is no empty space! Choose another number." << endl; // Error message
        }
    }
}
// Function to check for a win or tie
bool functionThree() {
    // Check for winning conditions (rows and columns)
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) || 
            (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
            return true; // A player has won
        }
    }
    // Check for winning conditions (diagonals)
    if ((space[0][0] == space[1][1] && space[0][0] == space[2][2]) || 
        (space[0][2] == space[1][1] && space[0][2] == space[2][0])) {
        return true; // A player has won
    }

    // Check for tie
    tie = true; // Assume it's a tie unless we find an empty space
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != '0') {
                tie = false; // Found an empty space, so it's not a tie
                break; // Exit the inner loop
            }
        }
    }
    return tie; // Return true if it's a tie
}
// Main function to run the game
int main() {
    cout << "Enter the name of the first player: "; // Prompt for player 1's name
    getline(cin, n1); // Read player 1's name
    cout << "Enter the name of the second player: "; // Prompt for player 2's name
    getline(cin, n2); // Read player 2's name
    cout << n1 << " is player 1 (x) and will play first." << endl; // Display player 1's info
    cout << n2 << " is player 2 (0)." << endl; // Display player 2's info

    // Main game loop
    while (!functionThree()) { // Continue until there's a winner or a tie
        functionTwo(); // Handle player input
    }

    // Determine the outcome of the game
    if (lastToken == 'x' && !tie) {
        cout << n1 << " you win you are a legend at least in this game"; // Player 1 wins
        cout << n2 << " ouch! that hurts more than stepping on a lego brick " << endl; // Player 2 loses
    } else if (lastToken == '0' && !tie) {
        cout << n2 << "you win you are a legend at least in this game " << endl; // Player 2 wins
        cout << n1 << "ouch! that hurts more than stepping on a lego brick  " << endl; // Player 1 loses
    } else {
        cout << "a tie i think the game is as confused as we are!" << endl; // It's a tie
    }
// Wait for user input before closing
    cout << "Press Enter to exit..."; // Prompt to exit
    cin.ignore(); // Ignore any leftover newline character in the input buffer
    cin.get(); // Wait for the user to press Enter

    return 0; // End of the program
}
