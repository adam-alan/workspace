//
// Created by zhuxingtian on 19-10-15.
//

#ifndef LODESTAR_BLOCKQUENE_H
#define LODESTAR_BLOCKQUENE_H



#include <condition_variable>
#include <mutex>
#include <queue>
namespace lodestar {
    template <typename DataType>
    class BlockQuene {

    public:
        BlockQuene()
        :mMutex(),
        mNotEmpty(),
        mQueue()
        {

        }
        BlockQuene(const BlockQuene &) = delete;
        BlockQuene operator=(const BlockQuene &) = delete;

        void put(const DataType & data){
            std::lock_guard<std::mutex> lockGuard(mMutex);
            mQueue.push(data);
            mNotEmpty.notify_one();
        }

        void put(const DataType && data){
            std::lock_guard<std::mutex> lockGuard(mMutex);
            mQueue.push(data);
            mNotEmpty.notify_one();
        }

        DataType get() {
            std::unique_lock<std::mutex> uniqueLock(mMutex);

            mNotEmpty.wait(uniqueLock,[this](){
                return not mQueue.empty();
            });


            DataType data(mQueue.front());
            mQueue.pop();
            return data;
        }

        std::size_t size() const {
            std::lock_guard<std::mutex> lockGuard(mMutex);
            return mQueue.size();
        }
    private:
        std::mutex mMutex;
        std::condition_variable mNotEmpty;
        std::queue<DataType> mQueue;
    };

}



#endif //LODESTAR_BLOCKQUENE_H
