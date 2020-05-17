# include <iostream>
# include <complex>
# include <iomanip>
# include <float.h> 
# include <cmath>
# include <sstream>
# include <string>
# include <cstdlib>

bool isZero(const double & num) {
    if (fabs(num) < DBL_EPSILON)
    {
        return true;
    }
    return false;
}


void outputComplex(const std::complex<double> & complex){

    double real = complex.real();
    double imag = complex.imag();
    //std::cout << std::string(real) << " " << std::string(imag) << std::endl;

    if (!isZero(real) && !isZero(imag))
    {
        if (imag >= DBL_EPSILON) {
            std::cout << std::fixed << std::setprecision(1) << complex.real() << "+" << complex.imag() << "i";
        } else {
            std::cout << std::fixed << std::setprecision(1) << complex.real() << complex.imag() << "i";
        }
    }
    if (isZero(real) && !isZero(imag)){
        std::cout << std::fixed << std::setprecision(1) << complex.imag() << "i";
    }
    if (!isZero(real) && isZero(imag)) {
        std::cout << std::fixed << std::setprecision(1) << complex.real();
    }
    if (isZero(real) && isZero(imag)) {
        std::cout << 0.0;
    }
    
}
int main(int argc, const char** argv) {
    double a1(0), b1(0), a2(0), b2(0);
    std::cin >> a1 >> b1 >> a2 >> b2;
    std::complex<double> num1(a1, b1);
    std::complex<double> num2(a2, b2);
    
    std::cout << "(";
    outputComplex(num1);
    std::cout << ") + ";
    std::cout << "(";
    outputComplex(num2);
    std::cout << ")";
    std::cout << " = ";
    outputComplex(num1 + num2);
    std::cout << std::endl;
  

    std::cout << "(";
    outputComplex(num1);
    std::cout << ") - ";
    std::cout << "(";
    outputComplex(num2);
    std::cout << ")";
    std::cout << " = ";
    outputComplex(num1 - num2);
    std::cout << std::endl;
    
    std::cout << "(";
    outputComplex(num1);
    std::cout << ") * ";
    std::cout << "(";
    outputComplex(num2);
    std::cout << ")";
    std::cout << " = ";
    outputComplex(num1 * num2);
    std::cout << std::endl;

    std::cout << "(";
    outputComplex(num1);
    std::cout << ") / ";
    std::cout << "(";
    outputComplex(num2);
    std::cout << ")";
    std::cout << " = ";
    outputComplex(num1 / num2);
    std::cout << std::endl;
    
    
    
    return 0;
}