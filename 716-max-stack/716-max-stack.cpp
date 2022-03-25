class MaxStack {
public:
    stack<pair<int,int>> maxStack;
    stack<int> aux;
    MaxStack() {
        
    }
    
    void push(int x) {
       if(!maxStack.empty())
       {
           int maxVal = max(maxStack.top().second, x);
           maxStack.push({x, maxVal});
       }
        else
            maxStack.push({x, x});
    }
    
    int pop() {
        int elem;
        if(!maxStack.empty())
        {
            elem = maxStack.top().first;
            maxStack.pop();
        }
        return elem;    
    }
    
    int top() {
        int elem;
        if(!maxStack.empty())
        {
            elem = maxStack.top().first;
        }
        return elem;
    }
    
    int peekMax() {
        int elem;
        if(!maxStack.empty())
        {
            elem = maxStack.top().second;
        }
        return elem;
        
    }
    
    int popMax() {
        int maxVal = peekMax();
        //Move all values to an aux stack until we get to the max value
        while(!maxStack.empty() && top() != maxVal)
        {
            aux.push(top());
            maxStack.pop();
        }
        //Remove the max element
        maxStack.pop();
        
        //Push back values from aux stack to maxStack with an updated maxValue
        while(!aux.empty())
        {
            int elemToAdd = aux.top();
            if(!maxStack.empty())
            {
                int currMax = peekMax();
                if( currMax >= elemToAdd)
                    maxStack.push({elemToAdd, currMax});
                else
                    maxStack.push({elemToAdd, elemToAdd});
            }
            else
            {
                 maxStack.push({elemToAdd, elemToAdd});
            }
            aux.pop();
        }
        return maxVal;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */