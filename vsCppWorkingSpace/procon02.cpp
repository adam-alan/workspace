# include <iostream>
# include <thread>
# include <mutex>
# include <condition_variable>
# include <queue>

# define MAX 20

int buffer[MAX];
int fill = 0;
int use = 0;
int count = 0;

std::condition_variable empty;
std::condition_variable full;
std::mutex mutex;

void put(int value)
{
    buffer[fill] = value;
    fill = (fill + 1) % MAX;
    count += 1;
}

int get(void)
{
    int tmp = buffer[use];
    use = (use + 1) % MAX;
    count -= 1;
    return tmp;
}




void produce()
{
    for (;;)
    {
        std::unique_lock<std::mutex> lock(mutex);
        empty.wait(lock, []()->bool { return count != MAX; });
        put(0);
        
        std::cout << "producer" << "\t" << count << std::endl;
        full.notify_one();
    }
}

void consume()
{   
    for (;;)
    {
        std::unique_lock<std::mutex> lock(mutex);
        full.wait(lock, []()->bool { return count != 0; });
        int tmp = get();
        std::cout << "consumer" << '\t' << tmp << "\t" << count << std::endl;
        empty.notify_one();
    }
}

int main(int argc, const char** argv) 
{
    std::thread producer(produce);
    std::thread consumer(consume);
    producer.join();
    consumer.join();
    return 0;
}