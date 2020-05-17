//
// Created by zhuxingtian on 19-12-31.
//

#ifndef NETWORKLIB_BUFFER_H
#define NETWORKLIB_BUFFER_H


# include <string>
# include <vector>
# include <algorithm>
# include <cassert>

using std::string;
using std::vector;
using std::copy;

class Buffer {
public:
    explicit Buffer(size_t initial_size = kInitialSize)
    :data_(kCheapPrependSize + initial_size),
    read_index_(kCheapPrependSize),
    write_index_(kCheapPrependSize)
    {

    }

    size_t ReadAbleBytes() const { return write_index_ - read_index_; }

    size_t WriteAbleBytes() const { return data_.size() - write_index_; }

    size_t PrependAbleBytes() const { return read_index_; }

    const char * Peek() const { return &(*data_.begin()) + read_index_; }

    void Retrieve(size_t length) {
        if (length <= ReadAbleBytes()) {
            read_index_ += length;
        } else {
            RetrieveAll();
        }
    }

    void RetrieveAll() {
        read_index_ = kCheapPrependSize;
        write_index_ = kCheapPrependSize;
    }

    string RetrieveAsString(int length) {
        string result(Peek(), length);
        Retrieve(length);
        return result;
    }
    void Append(const char * data,size_t length) {
        EnableAppend(length);
        copy(data, data + length, data_.begin() + write_index_);
        MoveWriteIndex(length);
    }
    void Append(const void * data,size_t length) {
        Append(static_cast<const char *>(data), length);
    }

    void PrePend(const void * data,size_t length) {
        assert(length <= PrependAbleBytes());
        read_index_ -= length;
        const char * temp_data = static_cast<const char *>(data);
        copy(temp_data, temp_data + length, data_.begin() + read_index_);
    }

    ssize_t ReadFd(int fd, int saved_errno);
    void swap(Buffer & buffer);
private:
    static const size_t kInitialSize = 1024;
    static const size_t kCheapPrependSize = 8;
    void MoveWriteIndex(size_t length){
        assert(WriteAbleBytes() >= length);
        write_index_ += length;
    }
    void ExpandSpace(size_t length) {
        if (WriteAbleBytes() + PrependAbleBytes() < length + kCheapPrependSize) {
            data_.resize(write_index_ + length);
        } else {
            assert(kCheapPrependSize < read_index_);
            size_t readable_bytes = ReadAbleBytes();
            copy(data_.begin() + read_index_,
                 data_.begin() + write_index_,
                 data_.begin() + kCheapPrependSize);
            read_index_ = kCheapPrependSize;
            write_index_ = read_index_ + readable_bytes;
            assert(readable_bytes == ReadAbleBytes());
        }
    }
    void EnableAppend(size_t length) {
        if (WriteAbleBytes() < length) {
            ExpandSpace(length);
        }
        assert(WriteAbleBytes() > length);
    }

    int read_index_;
    int write_index_;
    vector<char> data_;
};


#endif //NETWORKLIB_BUFFER_H
