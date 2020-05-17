//
// Created by zhuxingtian on 19-9-8.
//

#ifndef LODESTAR_BUFFER_H
#define LODESTAR_BUFFER_H

#include <vector>
#include <cstddef>
#include "Copyable.h"
namespace lodestar{
    class Buffer: public Copyable {
    public:
        static const std::size_t kCheapPrepend = 8;
        static const std::size_t kInitialSize = 1024;

        std::size_t readableBytes() const ;
        std::size_t writeableBytes() const ;
        std::size_t putFrontableBytes() const ;

        void append(const void *data,const std::size_t & length);
        void append(const char *data,const std::size_t & length);


        const char * peek() const ;
        void get(const std::size_t & length) ;
        void getUntil(const std::size_t & length) ;
        void getAll(const std::size_t & length) ;


    private:
        std::vector<char> buffer;
        std::size_t writerIndex;
        std::size_t readerIndex;
    };


}

#endif //NETBASE_BUFFER_H
