#include <iostream>
#include <string>
int aoti(std::string str);

int main(int argc, const char** argv) 
{
    //std::cout << aoti("42") << std::endl; 
    //std::cout << aoti("-42") << std::endl;
    //std::cout << aoti("4193 with words") << std::endl;
    //std::cout << aoti("-91283472332") << std::endl;
    //std::cout << aoti("words and 987") << std::endl;
    std::cout << aoti("  0000000000012345678") << std::endl;

    return 0;
}

int aoti(std::string str){
    int firstNotSpaceChar{0};
    while (str[firstNotSpaceChar] == ' ')
    {
        firstNotSpaceChar++;
    }

    bool isNegative{false};
    if (str[firstNotSpaceChar] == '-') {
        isNegative = true;
    }
    int numBeginIndex{firstNotSpaceChar};
    if (str[firstNotSpaceChar] == '+' or str[firstNotSpaceChar] == '-')
    {
        numBeginIndex = firstNotSpaceChar + 1;
    }
    int result = 0;
    while (numBeginIndex < str.length() and std::isdigit(str[numBeginIndex]))
    {
        int tmp = str[numBeginIndex] - '0';
        if (result > INT32_MAX / 10 or (result == INT32_MAX / 10 and tmp > 7))
        {
            return isNegative ? INT32_MIN : INT32_MAX;
        }
        result = result * 10 + tmp;
        numBeginIndex += 1;
    }
    return isNegative ? -result : result;
}
