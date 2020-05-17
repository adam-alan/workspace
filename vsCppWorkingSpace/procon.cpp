# include <pthread.h>
# include <iostream>
# include <sys/types.h>
# include <unistd.h>
# include <semaphore.h>
using std::cout;
using std::endl;

int in = 0, out = 0;
int buffer[10];
sem_t mutex;
sem_t full;
sem_t empty;
int mmutex = 1, mfull = 0, mempty = 10;


pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void wait(int *s)
{
    while (*s <= 0);
    *s -= 1;
}

void signal(int * s)
{

    
    *s += 1;
    
}

void * producer(void * arg)
{
    for (;;)
    {
        wait(&mempty);
        wait(&mmutex);
        //sem_wait(&empty);
        //sem_wait(&mutex);
        buffer[in] = 1;
        in = (in + 1) % 10;
        cout << "producer" << " " << in << endl;
        sleep(2);
        //sem_post(&mutex);
        //sem_post(&full);
        signal(&mmutex);
        signal(&mfull);
    }
}

void * consumer(void *arg)
{
    for (;;)
    {
        wait(&mfull);
        wait(&mmutex);
        
        //sem_wait(&full);
        //sem_wait(&mutex);
        buffer[out] = 0;
        out = (out + 1) % 10;
        cout << "consumer" << " " << out << endl;
        sleep(2);
        //sem_post(&mutex);
        //sem_post(&empty);
        signal(&mmutex);
        signal(&mempty);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t producer_t[2];
    pthread_t consumer_t[2];
    sem_init(&empty, 0, 10);
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
   
    for (int i = 0; i < 2; i++)
    {
        pthread_mutex_lock(&lock);
        pthread_create(&consumer_t[i], NULL, consumer, NULL);
        pthread_mutex_unlock(&lock);
    }
    for (int i = 0; i < 2; i++)
    {
        pthread_mutex_lock(&lock);
        pthread_create(&producer_t[i], NULL, producer, NULL);
        pthread_mutex_unlock(&lock);
    }

    for (int i = 0; i < 2;i++)
    {
        pthread_join(producer_t[i], NULL);
    }

    for (int i = 0; i < 2;i++)
    {
        pthread_join(consumer_t[i], NULL);
    }

    return 0;
}
