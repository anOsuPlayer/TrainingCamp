#include <iostream>
#include <fstream>
#include <string.h>

using std::cout, std::cin, std::string,
    std::ofstream, std::ifstream, std::endl;

char nextInt(char i) {
    if (i == 57) { return 48; }
    else { return ++i; }
}

char nextLetter(char v) {
    bool U = isupper(v);
    v = tolower(v);
    char ret;
    switch (v) {
        case 'a': ret = 'e'; break;
        case 'e': ret = 'i'; break;
        case 'i': ret = 'o'; break;
        case 'o': ret = 'u'; break;
        case 'u': ret = 'y'; break;
        case 'y': ret = 'a'; break;
        case 'd': ret = 'f'; break;
        case 'h': ret = 'j'; break;
        case 'n': ret = 'p'; break;
        case 't': ret = 'v'; break;
        case 'x': ret = 'z'; break;
        case 'z': ret = 'b'; break;
        default: ret = v+1; break; 
    }
    return (U) ? toupper(ret) : ret;
}

char process(char ch) {
    if (ch >= '0' && ch <= '9') {
        return nextInt(ch);
    }
    if (isalpha(ch)) {
        return nextLetter(ch);
    }
    return ch;
}

string filter(string in) {
    string newStr = "";
    for (int i = 0; i < in.length(); i++) {
        newStr += process(in.at(i));
    }
    return newStr;
}

int main() {
    ifstream in;
    ofstream out;

    in.open("input.txt");
    out.open("output.txt");

    int strs, s;
    in >> strs;

    string strings[strs];
    string tmp;

    for (int i = 0; i < strs+1; i++) {
        std::getline(in, tmp);
        strings[i] = tmp;
    }

    for (int i = 0; i < strs+1; i++) {
        out << filter(strings[i]) << "\n";
    }
}