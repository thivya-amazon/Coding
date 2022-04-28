#include <semaphore.h>

class H2O {
private:
    sem_t hydSem;
    sem_t oxySem;
    int hydCount;
    pthread_mutex_t hydMutex;

public:
    H2O() {
        sem_init(&hydSem, NULL, 1);
        sem_init(&oxySem, NULL, 0);  
        hydMutex = PTHREAD_MUTEX_INITIALIZER;
        hydCount = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        sem_wait(&hydSem);
        
        pthread_mutex_lock(&hydMutex);
        hydCount++;
        pthread_mutex_unlock(&hydMutex);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        
        if(hydCount % 2)
            sem_post(&hydSem);
        else
            sem_post(&oxySem);            
    }

    void oxygen(function<void()> releaseOxygen) {
        
        sem_wait(&oxySem);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        
        sem_post(&hydSem);
    }
};