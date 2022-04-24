#include <semaphore.h>
class FizzBuzz {
private:
    int n;
    sem_t fizzSem;
    sem_t buzzSem;
    sem_t fizzbuzzSem;

public:
    FizzBuzz(int n) {
        this->n = n;

        sem_init(&fizzSem, 0, 0);
        sem_init(&buzzSem, 0, 0);
        sem_init(&fizzbuzzSem, 0, 0);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for(int i = 3; i <= n; i+=3)
        {
             if(i % 5){
                sem_wait(&fizzSem);
                printFizz();
             }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for(int i = 5; i <= n; i+=5)
        {
             if(i % 3){
                sem_wait(&buzzSem);
                printBuzz();
             }
        }
        
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for(int i = 15; i <= n; i+=15)
        {
            sem_wait(&fizzbuzzSem);
            printFizzBuzz();
        }
        
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(int i = 1; i <= n; i++)
        {             
            if((i % 3 == 0) && (i % 5 == 0))
               sem_post(&fizzbuzzSem);
            else if(i % 3 == 0)
               sem_post(&fizzSem);
            else if(i % 5 == 0)
               sem_post(&buzzSem);
            else
                printNumber(i);
        }
    }
};