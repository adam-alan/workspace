template <typename T1,typename T2>
auto add(T1 t1,T2 t2)->decltype(t1+t2)
{
    return t1 + t2;
}


# include <iostream>

using std::cout;
using std::endl;

int main(int argc, const char** argv) 
{
    cout << add(1, 0.2) << endl;
    return 0;
}
