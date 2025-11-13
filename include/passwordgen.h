#include <vector>
#include <string>

namespace PasswordGenerator {

    const char CHAR_LIST[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-',
                            '_', '+', '=', '[', ']', '{', '}', '\\', '|', ';', ':', '\'', '\'',
                            ',', '<', '.', '>', '/', '?'};

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
    std::vector<char> getCharList(bool include_symbols,
                                  bool include_numbers);

    struct PasswordOptions {
        int length;
        bool includeUppercase;
        bool includeLowercase;
        bool includeNumbers;
        bool includeSymbols;
    };
    /**
     * @brief Generates a password of specified length from a list of ASII characters.
     * 
     * This function constructs a std::string password of specified length from the
     * provided vector of characters. The capitalization is randomly selected on
     * alphanumeric characters based on the \p mode parameter.
     * 
     * @param char_list The list of characters availablefor use in the password.
     * @param options The password options
     * 
     * @return
     */
    std::string get_password(std::vector<char> char_list,
                            PasswordOptions options);
    /**
     * Desc
     * 
     * @param
     * @param
     * 
     * @return
     */
    std::string generate_password(PasswordOptions options);
}
