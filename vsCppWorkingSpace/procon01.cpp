# include <iostream>
# include <sys/wait.h>
# include <functional>

using std::cin;
using std::cout;
using std::endl;

const size_t BUFSIZE = 10;

int counter = 0;

void producer(void)
{

}

void consumer(void)
{

}


void print(void)
{
    cout << "hahaaahahasdhf" << endl;
}

int main(int argc, const char** argv)
{
    std::function<void()> f;
    f = print;
    f();
    return 0;
}

