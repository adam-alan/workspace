# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/epoll.h>

# define TIMEOUT 5
# define BUF_LEN 1024


int main(int argc, char const *argv[])
{
    struct timeval tv;
    fd_set readfds;
    int ret;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    ret = select(STDIN_FILENO+1,
                 &readfds,
                 NULL,
                 NULL,
                 NULL);
    if (ret == -1)
    {
        perror("select");
        return 1;
    } 
    else if (!ret)
    {
        printf("%d seconds elapsed.\n",TIMEOUT);
        return 0;
    }
    if (FD_ISSET(STDIN_FILENO,&readfds))
    {
        char buf[BUF_LEN+1];
        int len;
        len = read(STDIN_FILENO, buf, BUF_LEN);
        if (len == -1)
        {
            perror("read");
            return 1;
        }
        if (len)
        {
            buf[len] = '\0';
            write(STDOUT_FILENO, buf, len+1);
            //printf("%s\n", buf);
        }
        return 0;
    }
    fprintf(stderr, "This should not happen!\n");
    return 1;
}
