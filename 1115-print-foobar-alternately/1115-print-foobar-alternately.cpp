
#include <semaphore.h>
class FooBar {
private:
    int n;
    sem_t fooSem;
    sem_t barSem;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&fooSem, 0, 0);
        sem_init(&barSem, 0, 0);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            if(i != 0)
                sem_wait(&barSem);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            sem_post(&fooSem);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&fooSem);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            sem_post(&barSem);
        }
    }
};