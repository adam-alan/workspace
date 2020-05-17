# include <iostream>

int main(int argc, const char** argv) {
    double open(0), high(0), lower(0), close(0);

    std::cin >> open >> high >> lower >> close;

    bool lowerShadow(false), upperShadow(false);
    
    if (close < open) {
        std::cout << "BW-Solid ";
    }

    if (close > open) {
        std::cout << "R-Hollow ";
    }

    if (close == open) {
        std::cout << "R-Cross";
    }

    if (lower < open && lower < close) {
        lowerShadow = true;
    }

    if (high > open && high > close) {
        upperShadow = true;
    }

    if (lowerShadow && upperShadow) {
        std::cout << " with Lower Shadow and Upper Shadow";
    }
    if (lowerShadow && !upperShadow) {
        std::cout << " with Lower Shadow";
    }

    if (upperShadow && !lowerShadow) {
        std::cout << " with Upper Shadow";
    }
    std::cout << std::endl;
    return 0;
}