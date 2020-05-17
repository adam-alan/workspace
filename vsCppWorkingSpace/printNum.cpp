# include <condition_variable>
# include <mutex>
# include <thread>
# include <chrono>
# include <iostream>
std::condition_variable even;
std::condition_variable odd;
std::mutex mutex;

int num = 0;

//print 奇数
void threadFunc1(){
    while (true) {
        std::unique_lock<std::mutex> lock(mutex);
        
        odd.wait(lock, [=]() -> bool {
            return num % 2 != 0;
        });
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        //std::cout << "threadFunc1:" << num << std::endl;
        std::cout << num << std::endl;
        num += 1;
        even.notify_one(); 
        
       /*
        if (num % 2 == 0) {
            odd.wait(lock);
        } else {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "odd thread " << num << std::endl;
            num += 1;
            even.notify_all(); 
        }
        */
    }
}

//print 偶数
void threadFunc2(){
    while (true) {
        std::unique_lock<std::mutex> lock(mutex);
        
        even.wait(lock, [=]() -> bool {
            return num % 2 == 0;
        });
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << num << std::endl;
        num += 1;
        odd.notify_one(); 
        /*
        if (num % 2 == 0) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "even thread " << num << std::endl;
            num += 1;
            odd.notify_all();
        } else {
            even.wait(lock);
        }
        */
    }
}

int main(int argc, const char** argv) {
    
    std::thread thread1(threadFunc1);
    std::thread thread2(threadFunc1);
    std::thread thread3(threadFunc1);
    std::thread thread4(threadFunc2);
    std::thread thread5(threadFunc2);
    std::thread thread6(threadFunc2);
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
    thread6.join();
    return 0;
}