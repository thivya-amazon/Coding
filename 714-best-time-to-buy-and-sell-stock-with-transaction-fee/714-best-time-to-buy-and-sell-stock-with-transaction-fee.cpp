class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int local = -fee;
        int global = 0;
        
        for(int i = 1; i < n; i++)
        {
            local = prices[i] - prices[i-1] + max(global - fee, local);
            global = max(global, local);
        }
        return global;
    }
};