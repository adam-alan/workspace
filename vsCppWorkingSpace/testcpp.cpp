#include<iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    char str[2][4]{"aaa", "bbb"};
    char(&arr)[4];

    arr = str;
    //arr[1] = str + 1;
    cout << *arr << endl;
    return 0;
}
