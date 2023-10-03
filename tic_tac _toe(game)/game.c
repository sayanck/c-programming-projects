#include <stdio.h>

// Function to print the Tic-Tac-Toe board
void printBoard(char board[3][3]) {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| ");
        for (int j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

// Function to check if the game is over
int isGameOver(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
            return 1;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    // Check if the board is full (a tie)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0; // The game is not over yet
        }
    }

    return -1; // It's a tie
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' },
                        { ' ', ' ', ' ' },
                        { ' ', ' ', ' ' } };
    int currentPlayer = 1;
    int row, col;
    int gameStatus = 0;

    printf("Tic-Tac-Toe Game\n");

    do {
        printBoard(board);
        printf("Player %d, enter row and column (e.g., 1 2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (currentPlayer == 1) {
            board[row - 1][col - 1] = 'X';
            currentPlayer = 2;
        } else {
            board[row - 1][col - 1] = 'O';
            currentPlayer = 1;
        }

        gameStatus = isGameOver(board);

    } while (gameStatus == 0);

    printBoard(board);

    if (gameStatus == -1) {
        printf("It's a tie!\n");
    } else {
        printf("Player %d wins!\n", currentPlayer == 1 ? 2 : 1);
    }

    return 0;
}