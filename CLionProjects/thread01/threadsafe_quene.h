//
// Created by zhuxingtian on 19-8-1.
//

#ifndef THREAD01_THREADSAFE_QUENE_H
#define THREAD01_THREADSAFE_QUENE_H

#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>

template <typename Type>
class threadsafe_quene {
public:
    explicit threadsafe_quene();
    explicit threadsafe_quene(const threadsafe_quene & other);
    void push(Type new_value);
    void wait_and_pop(Type & value);
    std::shared_ptr<Type> wait_and_pop();
    bool try_pop(Type & value);
    std::shared_ptr<Type> try_pop();
    bool empty() const;

private:
    mutable std::mutex mutex;
    std::queue<Type> queue;
    std::condition_variable cond;
};


#endif //THREAD01_THREADSAFE_QUENE_H
