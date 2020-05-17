# include <iostream>


void print_addr(const int & a){
    std::cout << &a << std::endl;
}

int main(int argc, const char** argv) {
    int a = 1;
    std::cout << &a << std::endl;
    int &re = a;
    std::cout << &re << std::endl;
    double num = 1.0 / 3;
    printf("%.30lf\n", num);
    
    print_addr(a);
    return 0;
}


