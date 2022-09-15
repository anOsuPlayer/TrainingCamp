#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl, std::string,
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

    int xK, yK = 0, xP, yP = rows-1;
    in >> xK >> xP;

    xK--; xP--;

    board[yK][xK] = 1;
    board[yP][xP] = 5;

    int x, y;
    for (int i = 0; x != 0 && y != 0; i++) {
        in >> x >> y;
        board[y-1][x-1] = 3;
    }

    for (int i = rows-1; i >= 0; i--) {
        for (int e = 0; e < cols; e++) {
            cout << board[i][e] << " ";
        }
        cout << endl;
    }

    int tendency = (xP < xK) ? -1 : (xP == xK) ? 0 : 1;
    string steps; string conclusion("C");
    bool breaker = true;

    while ((xP != xK || yP != yK) && breaker) {
        
        if (yP != yK) {
            if (board[yK+1][xK] <= 1 || board[yK+1][xK] == 5) {
                yK++;
                board[yK][xK] += 1;
                steps += "A";
            }
            else if (board[yK+1][xK] == 3) {
                if (yK == rows-2) {
                    if (xK == cols-1) {
                        xK--;
                        board[yK][xK] += 1;
                        steps += "S";
                    }
                    else {
                        if (tendency == 0) {
                            xK++;
                            board[yK][xK] += 1;
                            steps += "D";
                        }
                        else {
                            xK += tendency;
                            board[yK][xK] += 1;
                            steps += "D";
                        }
                    }
                }
                else {
                    if (xK != cols-1) {
                        xK++;
                        board[yK][xK] += 1;
                        steps += "D";
                    }
                    else {
                        xK--;
                        board[yK][xK] += 1;
                        steps += "S";
                    }
                }
            }
        }
        else {
            if (board[yK][xK+tendency] <= 1 || board[yK+1][xK] == 5) {
                xK += tendency;
                board[yK][xK] += 1;
                steps += (tendency == 1) ? "D" : "S";
            }
            else if (board[yK][xK+tendency] == 3) {
                if (yK == rows-1) {
                    yK--;
                    board[yK][xK] += 1;
                    steps += "B";
                }
                else {
                    xK++;
                    board[yK][xK] += 1;
                    steps += "D";
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int e = 0; e < cols; e++) {
                if (board[i][e] == 2) { breaker = false; }
                conclusion == "C";
                break;
            }
        }

        if (xK == xP && yK == yP) {
            conclusion == "P";
        }

        int tendency = (xP < xK) ? -1 : (xP == xK) ? 0 : 1;
    }

    cout << endl;
    for (int i = rows-1; i >= 0; i--) {
        for (int e = 0; e < cols; e++) {
            cout << board[i][e] << " ";
        }
        cout << endl;
    }

    out << steps << endl << conclusion;
}