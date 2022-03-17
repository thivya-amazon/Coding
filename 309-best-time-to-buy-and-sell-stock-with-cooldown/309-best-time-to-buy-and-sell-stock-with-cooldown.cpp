class Solution {
public:
    vector<int> global;
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> local(n);
    global.resize(n);
        
        local[0] = 0;
        global[0] = 0;
        
        for(int i = 1; i < n; i++)
        {
            local[i] = prices[i] - prices[i-1] + max(getGlobal(i-3), local[i-1]);
            global[i] = max(global[i-1], local[i]);
        }
        return global[n-1];
        
    }
    int getGlobal(int i)
    {
        if(i < 0)
            return 0;
        return global[i];
    }
};