#include <string>
#include <iostream>

int main(int argc, const char** argv) {
    std::string input;
    std::cin >> input;
    std::u16string s{U"哈哈"};
    if (input == "哈哈")
        {
            std::cout << u8"哈哈" << s.length() << std::endl;
    }
    std::cout << input.c_str() << std::endl;
    return 0;
}