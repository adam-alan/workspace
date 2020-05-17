# include <iostream>
# include "base/buffer.h"
# include "base/socket_native_api.h"
# include "base/log_stream.h"
#include "data_struct/binary_tree.h"
using namespace std;
using namespace native_api;


int main(int argc, const char** argv) {

    BinaryTree<int> binaryTree({1,3,7,9,12,5,10,11},{7,3,9,12,1,10,5,11});

    binaryTree.PreorderTraversal(binaryTree.Root());
    cout << endl;
    binaryTree.InorderTraversal(binaryTree.Root());
    cout << endl;
    binaryTree.LevelTraversal(binaryTree.Root());
    /*    sockaddr_in sockaddrIn;
    FromIpPort("127.0.0.1",6335,&sockaddrIn);
    cout << sockaddrIn.sin_port << endl;
    cout << sockaddrIn.sin_addr.s_addr << endl;
    LogStream logStream;
    logStream << 1 << '\t' << 3.1415926 << '\t' << "sss";

    cout << logStream.string << endl;*/
    return 0;
}

/*

Buffer buffer;
cout << buffer.ReadAbleBytes() << endl;
cout << buffer.WriteAbleBytes() << endl;
cout << buffer.PrependAbleBytes() << endl;
string string1{"hello world"};
buffer.Append(string1.c_str(), string1.length());
cout << buffer.Peek() << endl;
cout << string1.length() << "\t" << buffer.ReadAbleBytes() << endl;

buffer.Retrieve(string1.length());
cout << buffer.Peek() << endl;
cout << string1.length() << "\t" << buffer.ReadAbleBytes() << endl;*/
