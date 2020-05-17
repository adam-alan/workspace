# include <iostream>
# include <arpa/inet.h>
using namespace std;

class Test{
public:
    Test() {
        cout << "constructor" << endl;
    }
    Test(const Test & test){
        cout << "copy constructor" << endl;
    }
    Test& operator=(const Test & test){
        cout << "assign operator" << endl;
        return *this;
    }
 
    ~Test() {
        cout << "destructor" << endl;
    }
};

void f1(Test test){

}

void f2(const Test & test){
    
}

union var{
    int a;
    float b;
    double c;
};

int
main(int argc, char const *argv[])
{

    std::cout << __FILE__ << '\t' << __LINE__ << std::endl;
    std::cout << sizeof (sockaddr_in) << std::endl;
    std::cout << sizeof (sockaddr_in6) << std::endl;
    std::cout << sizeof (sockaddr)<< std::endl;
    var v;
    v.a = 2;
    v.b = 3.1;
    v.c = 3.1415926;
    std::cout << v.a << std::endl;
    std::cout << v.b << std::endl;
    std::cout << v.c << std::endl;
    
    return 0;
}
