#include "../include/passwordgen.h"
#include <iostream>
#include <random>

using namespace std;

// Default character list that can be used to create passwords besides {0-9, a-z, A-Z}
namespace PasswordGenerator {

    string PasswordGen::generatePassword(PasswordOptions options) {
        vector<char> charList = getCharList(options.includeSymbols, options.includeNumbers);
        string password = getPassword(charList, options);
        return password;
    }

    vector<char> PasswordGen::getCharList(bool includeSymbols, bool includeNumbers) {
        vector<char> charList = {};

        for (char c = 'a'; c <= 'z'; c++) {
            charList.push_back(c);
        }
        
        if (includeSymbols) {
            for (const char& c : CHAR_LIST) {
                charList.push_back(c);
            }
        }

        if (includeNumbers) {
            for (char c = '0'; c <= '9'; c++) {
                charList.push_back(c);
            }
        }

        return charList;
    }

    string PasswordGen::getPassword(std::vector<char> charList, PasswordOptions options) {
        // Create seed
        random_device rd;

        // Seed ranlux48 generator
        ranlux48 gen(rd());
        
        string pw = "";
        for (int i = 0; i < options.length; i++) {
            // Get random number [0, charList length) for index of charList to grab from
            uniform_int_distribution<> distrib(0, charList.size() - 1);
            int charIndex = distrib(gen);
            
            char curChar = charList.at(charIndex);

            if (!isalpha(curChar)) {
                pw.push_back(curChar);
            } else {
                if (options.includeUppercase && options.includeLowercase) {
                    // 50% chance of upper or lowercase letter
                    uniform_int_distribution<> distrib(0, 1);
                    int upperOrLower = distrib(gen);

                    if (upperOrLower == 0) {
                        pw.push_back(toupper(curChar));
                    } else {
                        pw.push_back(tolower(curChar));
                    }

                } else if (options.includeUppercase && !options.includeLowercase) {
                    pw.push_back(toupper(curChar));
                } else if (!options.includeUppercase && options.includeLowercase) {
                    pw.push_back(curChar);
                }
            }
        }
        return pw;
    }

} // namespace PasswordGenerator

/*int main() {
    cout << "Password length (minimum 8) | allow uppercase | allow lowercase | include numbers | include symbols" << endl;
    cout << "Example input: 16 N N Y Y" << "\nNOTE: For uppercase\\lowercase only, you can only select one option. If both are selected it will default to including uppercase and lowercase letters." << endl;
    /*int pw_len = 8;
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

    //vector<char> charList = get_charList(include_symbols, include_numbers);
    vector<char> charList = get_charList(true, true);
    //string password = get_password(charList, pw_len, uppercase_only, lowercase_only);
    string password = get_password(charList, 16, true, true);
    cout << password << endl;
    return 0;
}*/