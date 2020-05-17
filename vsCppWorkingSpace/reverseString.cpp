# include <iostream>
# include <string>



std::string reverseString(std::string str){
    if (str.length() == 1) {
        return str;
    }
    return str.substr(str.length() - 1, str.length()) + reverseString(str.substr(0, str.length() - 1));
}

int main(int argc, const char** argv) {
    std::string s{"123456"};
    std::cout << s.substr(s.length() - 1, s.length()) << std::endl;
    std::cout << reverseString(s) << std::endl;
    return 0;
}