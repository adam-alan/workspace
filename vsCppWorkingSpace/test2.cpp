# include <iostream>
# include <thread>

void *task(void*){
    int *a = new int(0);
    std::cout << a << std::endl;
    return nullptr;
}

int main(int argc, char const *argv[])
{
    ::pthread_t
    ::pthread_t  t1,t2,t3;
    ::pthread_create(&t1, nullptr, task, nullptr);
    ::pthread_create(&t2, nullptr, task, nullptr);
    ::pthread_create(&t3, nullptr, task, nullptr);
    ::pthread_join(t1,nullptr);
    ::pthread_join(t2,nullptr);
    ::pthread_join(t3,nullptr);
    return 0;
}
