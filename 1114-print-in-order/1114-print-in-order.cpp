#include <semaphore.h>
class Foo {
private:
    sem_t firstFunc;
    sem_t secondFunc;
public:
    Foo() {
        sem_init(&firstFunc, 0, 0);
        sem_init(&secondFunc, 0, 0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&firstFunc);
    }

    void second(function<void()> printSecond) {
        sem_wait(&firstFunc);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&secondFunc);
    }

    void third(function<void()> printThird) {
        sem_wait(&secondFunc);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};