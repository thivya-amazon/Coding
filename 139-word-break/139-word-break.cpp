class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        for(auto s : wordDict)
            dict.insert(s);
        int n = s.size();
        vector<bool> dp(n+1, false);
        //Empty string is present in dict
        dp[0] = true;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < i; j++)
            {
                string curr = s.substr(j, i-j);
                if(dp[j] && dict.count(curr))
                {
                    dp[i] = true;
                    break;
                }                    
            }
        return dp[n];
    }
};