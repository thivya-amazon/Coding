#include <semaphore.h>
class ZeroEvenOdd {
private:
    int n;
    sem_t zeroSem;
    sem_t oddSem;
    sem_t evenSem;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&zeroSem, 0, 1);
        sem_init(&oddSem, 0, 0);
        sem_init(&evenSem, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
       
        for(int i = 1; i <= n; i++)
        {
            sem_wait(&zeroSem);
            printNumber(0);
            if(i % 2)
                sem_post(&oddSem);
            else
                sem_post(&evenSem);
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2; i <= n; i+=2)
        {
            sem_wait(&evenSem);
            printNumber(i);
            sem_post(&zeroSem);
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i <= n; i+=2)
        {
            sem_wait(&oddSem);
            printNumber(i);
            sem_post(&zeroSem);
        }
    }
};