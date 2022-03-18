class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> global2(n, 0);
        vector<int> local2(n, 0);
        vector<int> global1(n, 0);
        vector<int> local1(n, 0);
    

        for(int i = 1; i < n; i++)
        {
            local1[i] = prices[i] - prices[i-1] + max(0, local1[i-1]);
            global1[i] = max(global1[i-1], local1[i]);
            
            local2[i] = prices[i] - prices[i-1] + max(global1[i-1], local2[i-1]);
            global2[i] = max(global2[i-1], local2[i]);
        }
        return global2[n-1];
    }
};