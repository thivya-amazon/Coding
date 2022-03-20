class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        //No squares can be formed with 1 row
        // if(rows <= 1)
        //     return 0;
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
        
        int maxLen = 0;
        for(int i = 1; i <= rows; i++)
            for(int j = 1; j <= cols; j++)
            {
                if(matrix[i-1][j-1] == '1')
                {
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        return maxLen*maxLen;
        
    }
};