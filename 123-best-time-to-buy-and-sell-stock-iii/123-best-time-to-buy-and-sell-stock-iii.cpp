class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prevGlobal1 = 0;
        int global2 = 0;
        int local2 = 0;
        int global1 = 0;
        int local1 = 0;
        
        for(int i = 1; i < n; i++)
        {
            local1 = prices[i] - prices[i-1] + max(0, local1);
            prevGlobal1 = global1;
            global1 = max(global1, local1);
            local2 = prices[i] - prices[i-1] + max(prevGlobal1, local2);
            global2 = max(global2, local2);
        }
        return global2;
    }
};