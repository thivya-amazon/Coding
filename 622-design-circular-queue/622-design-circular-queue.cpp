class MyCircularQueue {
public:
    int capacity;
    int size;
    vector<int> queue;
    int front;
    int rear;
    MyCircularQueue(int k) {
        capacity = k;
        queue.resize(capacity);
        size = 0;
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        if(isEmpty())
        {
            front = 0;
            rear = 0;
            queue[rear] = value;            
        }
        else
        {
            rear = (rear + 1) % capacity;
            queue[rear] = value;
        }
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        front = (front + 1) % capacity;
        size--;
        if(size == 0)
        {
            front = -1;
            rear = -1;
        }
        return true;        
    }
    
    int Front() {
        if(!isEmpty())
            return queue[front];
        return -1;
    }
    
    int Rear() {
        if(!isEmpty())
            return queue[rear];
        return -1;
    }
    
    bool isEmpty() {
        if(size == 0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(size == capacity)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */