# include <unistd.h>
# include <semaphore.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <iostream>
sem_t sem;

int counter = 0;
void count()
{
    sem_wait(&sem);
    counter += 1;
    sem_post(&sem);
}

int main(int argc, const char** argv) {
    sem_init(&sem, 0, 1);
    pid_t pid;
    count();
    for (int i = 0; i < 5;i++) {
        pid = fork();
 
        switch(pid) {
            case 0:
                count();
                std::cout << counter << "\tchild" << std::endl;    
                break;
            case -1:
                std::cerr << "error" << std::endl;
                exit(1);
                break;
            default:
                wait(nullptr);
                break;
        }
    
    }
    return 0;
}