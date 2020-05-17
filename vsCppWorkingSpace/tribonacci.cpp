# include <iostream>

int main(int argc, const char** argv) {
    int64_t first = 0;
    int64_t second = 1;
    int64_t third = 1;
    int64_t result = 0;
    
    int64_t num = 0;
    std::cin >> num;
    switch (num)
    {
    case 0:
        std::cout << first << std::endl;
        break;
    case 1:
        std::cout << second << std::endl;
        break;
    case 2:
        std::cout << third << std::endl;
        break;
    default:
        for (int i = 2; i < num;i++){
            result = first + second + third;
            first = second;
            second = third;
            third = result;
        }
        std::cout << result << std::endl;
        break;
    }

    return 0;
}