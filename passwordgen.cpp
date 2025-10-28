#include "passwordgen.h"
#include <iostream>
#include <random>

using namespace std;


// Default character list that can be used to create passwords besides {0-9, a-z, A-Z}
const char CHAR_LIST[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-',
                            '_', '+', '=', '[', ']', '{', '}', '\\', '|', ';', ':', '\'', '\'',
                            ',', '<', '.', '>', '/', '?'};

vector<char> get_char_list(bool include_symbols, bool include_numbers) {
    vector<char> char_list = {};

    for (char c = 'a'; c <= 'z'; c++) {
        char_list.push_back(c);
    }
    
    if (include_symbols) {
        for (char c : CHAR_LIST) {
            char_list.push_back(c);
        }
    }

    if (include_numbers) {
        for (char c = '0'; c <= '9'; c++) {
            char_list.push_back(c);
        }
    }

    return char_list;
}

string get_password(std::vector<char> char_list, int len, bool include_uppercase, bool include_lowercase) {
    // Create seed
    random_device rd;

    // Seed ranlux48 generator
    ranlux48 gen(rd());
    
    string pw = "";
    for (int i = 0; i < len; i++) {
        // Get random number [0, char_list length) for index of char_list to grab from
        uniform_int_distribution<> distrib(0, char_list.size() - 1);
        int char_index = distrib(gen);
        
        char cur_char = char_list.at(char_index);

        //TODO: FIX THIS,BAD LOGIC
        if (!isalpha(cur_char)) {
            pw.push_back(cur_char);
        } else {
            if (include_uppercase && include_lowercase) {
                // 50% chance of upper or lowercase letter
                uniform_int_distribution<> distrib(0, 1);
                int upper_or_lower = distrib(gen);
                if (upper_or_lower == 0) {
                    pw.push_back(toupper(cur_char));
                } else {
                    pw.push_back(tolower(cur_char));
                }
            } else if (include_uppercase && !include_lowercase) {
                pw.push_back(toupper(cur_char));
            } else if (!include_uppercase && include_lowercase) {
                pw.push_back(cur_char);
            }
        }
    }
    return pw;
}

string generate_password(int len, bool include_uppercase, bool include_lowercase, bool include_symbols, bool include_numbers) {
    vector<char> char_list = get_char_list(include_symbols, include_numbers);
    string password = get_password(char_list, len, include_uppercase, include_lowercase);
    return password;
}

// Potentially for use in a C# .NET app
/*
extern "C" __declspec(dllexport) const char* generate_password_c(int len, bool uppercase_only, bool lowercase_only, bool include_symbols, bool include_numbers) {
    static string password = generate_password(len, uppercase_only, lowercase_only, include_symbols, include_numbers);
    return password.c_str();
}
*/
/*
int main() {
    cout << "Password length (minimum 8) | uppercase only | lowercase only | include numbers | include symbols" << endl;
    cout << "Example input: 16 N N Y Y" << "\nNOTE: For uppercase\\lowercase only, you can only select one option. If both are selected it will default to including uppercase and lowercase letters." << endl;
    int pw_len = 8;
    char uppercase_char = 'N';
    char lowercase_char = 'N';
    char symbols_char;
    char numbers_char;

    cin >> pw_len >> uppercase_char >> lowercase_char >> numbers_char >> symbols_char;

    bool uppercase_only = false;
    bool lowercase_only = false;
    bool include_symbols = true;
    bool include_numbers = true;

    if (uppercase_char == 'Y' && lowercase_char == 'N') {
        uppercase_only = true;
    } else if (uppercase_char == 'N' && lowercase_char == 'Y') {
        lowercase_only = true;
    }

    if (symbols_char == 'N') {
        include_symbols = false;
    }
    if (numbers_char = 'N') {
        include_numbers = false;
    }

    vector<char> char_list = get_char_list(include_symbols, include_numbers);
    string password = get_password(char_list, pw_len, uppercase_only, lowercase_only);
    cout << password << endl;
    return 0;
}
*/