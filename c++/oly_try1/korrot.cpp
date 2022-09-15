#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl,
    std::ofstream, std::ifstream;

int main() {
    ofstream out;
    ifstream in;

    in.open("input.txt");
    out.open("output.txt");

    int rows, cols;
    in >> rows >> cols;

    int board[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int e = 0; e < cols; e++) {
            board[i][e] = 0;
        }
    }

    int K, P;
    in >> K >> P;

    board[1][K-1] = 1;
    board[rows-1][P-1] = 5;

    int x, y;
    for (int i = 0; x != EOF; i++) {
        in >> x >> y;
        board[x][y] = 3;
    }

    for (int i = 0; i < rows; i++) {
        for (int e = 0; e < cols; e++) {
            cout << board[i][e] << " ";
        }
        cout << "\n";
    }
}