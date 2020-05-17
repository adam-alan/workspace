# include <iostream>
int selectKing(int n) {
    if (n == 1) {
        return 0;
    }
    return (selectKing(n - 1) + 3) % n;
}
int main(int argc, const char** argv) {
    int n = 0;
    std::cin >> n;
    std::cout << selectKing(n) + 1 << std::endl;
    return 0;
}