#include <iostream>
#include <fstream>

using std::cout, std::cin, std::string,
    std::ofstream, std::ifstream, std::endl;

int main() {
    ofstream out;
    ifstream in;

    out.open("output.txt");
    in.open("input.txt");

    int ways, galleries, whereHarmony, whereSpike;
    in >> ways >> galleries >> whereHarmony >> whereSpike;

    int path[galleries][3];
    for (int i = 0; i < galleries; i++) {
        in >> path[i][0] >> path[i][1] >> path[i][2];
    }
    int steps = 0; int beginning = whereHarmony;

    while (whereHarmony != whereSpike) {
        int minLight = galleries+1;
        for (int i = 0 ; i < galleries; i++) {
            if (path[i][2] <= minLight && path[i][0] == whereHarmony) {
                minLight = path[i][2];
            }
        }
        for (int i = 0; i < galleries; i++) {
            if (path[i][2] == minLight && path[i][0] == whereHarmony) {
                whereHarmony = path[i][1];
                int swap = path[i][1];
                path[i][1] = path[i][0];
                path[i][0] = swap; 
                i = ways;
            }
        }
        steps++;
        if (whereHarmony == beginning) {
            steps = -1;
            break;
        }
    }

    out << steps;

    out.close();
    in.close();
}