class MyQueue {
public:
    stack<int> s1;          //main stack
    stack<int> s2;          //aux stack
    MyQueue() {
        
    }
    
    //Push operation should ensure the first element is on the top of the stack
    void push(int x) {
        if(s1.empty())
        {
            s1.push(x);
            return;
        }
        int elem = s1.top();
        s1.pop();
        push(x);
        s1.push(elem);
    }
    
    int pop() {
        if(empty())
            return -1;
        int elem = peek();
        s1.pop();
        return elem;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */