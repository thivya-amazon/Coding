class Solution {
public:
    vector<int> global;
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int local = 0;
    global.resize(n);
        
        global[0] = 0;
        
        for(int i = 1; i < n; i++)
        {
            local = prices[i] - prices[i-1] + max(getGlobal(i-3), local);
            global[i] = max(global[i-1], local);
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