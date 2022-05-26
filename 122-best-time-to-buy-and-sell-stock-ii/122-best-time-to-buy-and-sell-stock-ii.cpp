class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int local = 0;
        int global = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            local = prices[i] - prices[i-1] + max(global, local);
            global = max(global, local);
        }
        return global;
    }
};