//#include "passwordgen.h"
#include <iostream>
#include <random>

using namespace std;

vector<char> get_char_list(bool include_symbols, bool include_numbers, bool uppercase_only, bool lowercase_only) {
    vector<char> char_list = {};

    // Add characters a-z and A-Z
    for (char c = 'a'; c <= 'z'; c++) {
        char_list.push_back(c);
    }

    
    for (char c = 'A'; c <= 'Z'; c++) {
        char_list.push_back(c);
    }
    
    return char_list;
}

int main() {
    random_device rd;
    mt19937 gen(rd());

    vector<char> char_list = get_char_list(true, true);

    for (int n : char_list) {
        cout << (char)n << ' ';
    }
    cout << endl;
    return 0;
}

