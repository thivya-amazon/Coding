class Solution {
public:
    bool helper(string s, string p, int i, int j, vector<vector<int>>& dp)
    {
        if(j == p.size())
            return i == s.size();
        if(dp[i][j] >= 0)
            return (bool)dp[i][j];
        bool result = 0;
        //1. Check the first character of s to see if it matches with p
        bool firstMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
        
        //2. Check if the 2nd character of p is a *
        if(j+1 < p.size() && p[j+1] == '*')
        {
            //2 options : 
            //1. Consider * to be a number of prefix character p[j] and skip that and move to the next char in p
            //2. Consider * to be 0 and move the index of s to check for next match in p
            result = helper(s, p, i, j+2, dp) || (firstMatch && helper(s, p, i+1, j, dp));
        }
        else
            result = firstMatch && helper(s, p, i+1, j+1, dp);
        
        dp[i][j] = result;
        return result;
        
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size(), -1));
        return helper(s, p, 0, 0, dp);
        
        }
};