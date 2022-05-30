class MyCircularQueue {
public:
    vector<int> arr;
    int capacity;
    int front;
    int rear;
    MyCircularQueue(int k) {
        capacity = k;
        arr.resize(capacity);
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value) {
        //Full
        if(isFull())
            return false;
        //Empty
        if(isEmpty())
        {
            front = 0;
            rear = 0;
            arr[rear] = value;
            return true;
        }
        //Normal
        rear = (rear+1) % capacity;
        arr[rear] = value;
        return true;
        
    }
    
    bool deQueue() {
        //Empty
        if(isEmpty())
            return false;
        //last element
        if(front == rear)
        {
            front = -1;
            rear = -1;
            return true;
        }
        front = (front + 1) % capacity;
        return true;
    }
    
    int Front() {
        if(!isEmpty())
            return arr[front];
        return -1;
    }
    
    int Rear() {
        if(!isEmpty())
            return arr[rear];
        return -1;
    }
    
    bool isEmpty() {
        if(front == -1 && rear == -1)
            return true;
        return false;
    }
    
    bool isFull() {
        if(front == (rear+1) % capacity)
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