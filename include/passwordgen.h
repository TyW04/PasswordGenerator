#ifndef PASSWORD_GEN_H
#define PASSWORD_GEN_H

#include <vector>
#include <string>

namespace PasswordGenerator {

    constexpr char CHAR_LIST[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-',
                            '_', '+', '=', '[', ']', '{', '}', '\\', '|', ';', ':', '\'', '\'',
                            ',', '<', '.', '>', '/', '?'};

    struct PasswordOptions {
        int length = 8;
        bool includeUppercase = true;
        bool includeLowercase = true;
        bool includeNumbers = true;
        bool includeSymbols = true;
    };

    /**
     * @brief A class for generating secure passwords.
     */
    class PasswordGen {
        public:
            // Public API Function

            /**
             * @brief Generates a new password based on the provided options.
             * 
             * This function is the primary API call. It handles all internal logic to produce
             * a password that matches the constraints in @p options.
             * 
             * @param options A structure holding the password constraints set by the user.
             * 
             * @return A new std::string containing the generated password.
             */
            std::string generatePassword(PasswordOptions options);

        private:
            /**
             * @brief Generates a character list composed of lowercase letters, and optionally symbols
             * and numbers.
             * 
             * This function constructs a vector of charactres for use in password generation.
             * It always includes the ASCII range 'a'-'z'.
             * 
             * @param include_symbols If true, includes symbols in the character list.
             * @param include_numbers If true, include numbers in the character list.
             * 
             * @return A vector of characters containingat minimum 'a'-'z', optionally including
             * '0'-'9' and elements from \c CHAR_LIST.
             */
            std::vector<char> getCharList(bool includeSymbols, bool includeNumbers);

            /**
             * @brief Generates a password of specified length from a list of ASII characters.
             * 
             * This function constructs a std::string password of specified length from the
             * provided vector of characters. The capitalization is randomly selected on
             * alphanumeric characters based on the @p mode parameter within the 
             * PasswordOptions struct.
             * 
             * @param char_list The list of characters available for use in the password.
             * @param options The password options container (length, includeUppercase,
             * includeLowercase, includeNumbers, includeSymbols).
             * 
             * @return A string containing the resulting password.
             */
            std::string getPassword(std::vector<char> charList, PasswordOptions options);

    };
} // namespace PasswordGenerator

#endif // PASSWORD_GEN_H