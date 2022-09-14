#include <iostream>
#include <fstream>

using std::string, std::cout, std::cin,
    std::ofstream, std::ifstream;

void sort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int e = 0; e < size-i-1; e++) {
            if (arr[e] < arr[e+1]) {
                int swap = arr[e];
                arr[e] = arr[e+1];
                arr[e+1] = swap;
            }
        }
    }
}

int main() {
    ifstream in;
    ofstream out;

    in.open("input.txt");
    out.open("output.txt");

    int A, B, N;
    in >> A >> B >> N;
    int capts[N], original[N];
    
    int end[N][2];
    for (int i = 0; i < N; i++) {
        end[i][0] = 0; end[i][1] = 0;
    }

    for (int i = 0; i < N; i++) {
        in >> original[i];
        capts[i] = original[i];
    }
    sort(capts, N);

    for (int i = 0; B > 0 && i < N; i++) {
        while (end[i][1] < capts[i] && B >= 0) {
            B--; end[i][1]++;
        }
    }

    for (int i = N-1; A > 0 && i >= 0; i--) {
        while (end[i][0] < capts[i] && A >= 0) {
            A--; end[i][0]++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int e = 0; e < N; e++) {
            if (original[i] == end[e][0] || original[i] == end[e][1]) {
                out << end[e][0] << " " << end[e][1] << "\n";
                e = N;
            }
        }
    }
}