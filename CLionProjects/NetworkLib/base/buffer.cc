//
// Created by zhuxingtian on 19-12-31.
//

#include "buffer.h"
#include "socket_native_api.h"


ssize_t Buffer::ReadFd(int fd, int saved_errno) {
    struct iovec vec[2];
    char extra_buf[65536];

    const size_t writeable_bytes{WriteAbleBytes()};
    vec[0].iov_base = &(*data_.begin()) + write_index_;
    vec[0].iov_len = writeable_bytes;
    vec[1].iov_base = extra_buf;
    vec[1].iov_len = sizeof(extra_buf);
    //native_api::ReadVector(fd, vec, 2);
}