# include <sys/msg.h>
# include <unistd.h>
# include <iostream>


int main(int argc, char const *argv[])
{
    int msqid;
    ::msqid_ds info;
    ::msgbuf buf;

    msqid = msgget(IPC_PRIVATE,SVMSG_MODE) 
    return 0;
}
