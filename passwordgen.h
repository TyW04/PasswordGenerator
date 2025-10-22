#include <vector>
#include <string>

std::string generate_password(int len, bool uppercase_only, bool lowercase_only, bool include_symbols, bool include_numbers);
std::vector<char> get_char_list(bool include_symbols, bool include_numbers);
std::string get_password(std::vector<char> char_list, int len, bool uppercase_only, bool lowercase_only);