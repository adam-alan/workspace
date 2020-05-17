# include <iostream>


struct pollfd;

int main(int argc, char const *argv[])
{
    double x = 0.0;
    std::cin >> x;
    if (x < -1)
    {
        std::cout << -x << std::endl;
        
    }
    else if (x > -1 and x < 0)
    {
        std::cout << 1 << std::endl;
    }
    else 
    {
        std::cout << x << std::endl;
    }

    return 0;
}
