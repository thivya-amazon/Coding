class StockSpanner {
public:
    int currDay;
    //push {day,price} pair into stack
    stack<pair<int, int>> mono;
    int span;
    StockSpanner() {
        currDay = -1;
        span = 0;
    }
    
   
    int next(int price) {
        //We assume this function is called everyday. So increment currDay for every call
        currDay++;
        //Find the day where the price was greater thab the curr day. That's where we hit the wall
        while(!mono.empty() && price >= mono.top().second)
            mono.pop();
        if(!mono.empty())
            span = currDay - mono.top().first;
        else
            span = currDay + 1;
        mono.push({currDay, price});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */