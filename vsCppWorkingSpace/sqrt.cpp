# include <iostream>

float sqrt(float number) {

    long i(0);
    float x2(0), y(0);
    const float threeHalfs = 1.5F;
    
    x2 = number * 0.5F;
    
    y = number;
    
    i = *(long *)&y;
    
    i = 0X5F3759DF - (i >> 1);
    
    y = *(float *)&i;
    
    y = y * (threeHalfs - (x2 * y * y));
    return y;
}

int main(int argc, char const *argv[])
{

    std::cout << 1/sqrt(16) << std::endl;
    return 0;
}
