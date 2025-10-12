 #include <vector>
 #include <string>

 // Default character list that can be used to create passwords besides {0-9, a-z, A-Z}
 const char CHAR_LIST[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-',
                            '_', '+', '=', '[', ']', '{', '}', '\\', '|', ';', ':', '\'', '\'',
                            ',', '<', '.', '>', '/', '?'};

 std::vector<char> get_char_list(bool include_symbols, bool include_numbers);
 std::string get_password(std::vector<char> char_list, int len, bool uppercase_only, bool lowercase_only);
