class MovingAverage {
public:
    int k;
    queue<int> q;
    int totalSoFar;
    MovingAverage(int size) {
        k = size;
        totalSoFar = 0;
    }
    
    double next(int val) {
        q.push(val);
        totalSoFar += val;           
        if(q.size() > k)
        {
            totalSoFar -= q.front();
            q.pop();
        }
        return (double)(totalSoFar)/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */