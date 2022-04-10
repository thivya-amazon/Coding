#include <semaphore.h>

class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        maxCapacity = capacity;
        buffSize = 0;
        sem_init(&elem, 0, 0);
        sem_init(&space, 0, capacity);
    }
    
    void enqueue(int element) {
        sem_wait(&space);            
        mu.lock();
        buffSize++;
        q.push(element);
        mu.unlock();      
        sem_post(&elem);
    }
    
    int dequeue() {
        int value = -1;
        sem_wait(&elem);

        mu.lock();
        buffSize--;
        value = q.front();
        q.pop();
        mu.unlock();  
        sem_post(&space);
        return value;        
    }
    
    int size() {
        return buffSize;
    }
    private:
    int maxCapacity;
    int buffSize;
    queue<int> q;
    mutex mu;
    sem_t space;
    sem_t elem;
};