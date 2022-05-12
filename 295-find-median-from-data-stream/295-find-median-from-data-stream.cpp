class MedianFinder {
public:
    priority_queue<int> maxHeap;                            //stores numbers less than median
    priority_queue<int, vector<int>, greater<int>> minHeap; //stores numbers greater than median
    double median;
    MedianFinder() {
        median = 0.0;
    }
    
    void addNum(int num) {

        if(maxHeap.size() > minHeap.size())
        {
            if(num < median)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
            else
                minHeap.push(num);
            median = ((double)maxHeap.top() + minHeap.top())/2;
        }
        else if(minHeap.size() > maxHeap.size())
        {
            if(num > median)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            else
                maxHeap.push(num);
            median = ((double)maxHeap.top() + minHeap.top())/2;
        }
        else
        {
            if(num > median)
            {
                minHeap.push(num);
                median = minHeap.top();
            }
            else
            {
                maxHeap.push(num);
                median = maxHeap.top();
            }
        }
            
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */