class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0)
            return 0;
        vector<vector<int>> global(k+1, vector<int>(n, 0));
        vector<vector<int>> local(k+1, vector<int>(n, 0));
        
        for(int i = 1; i < n; i++)
        {
            for(int t = 1; t <= k; t++)
            {
                local[t][i] = prices[i] - prices[i-1] + max(global[t-1][i-1], local[t][i-1]);
                global[t][i] = max(global[t][i-1], local[t][i]);
            }
        }
        return global[k][n-1];
    }
};