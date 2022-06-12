class Solution {
public:
    int palHelper(int left, int right, string& s, vector<vector<int>>& memo)
    {
        if(left == right)
            return 1;
        if(left > right)
            return 0;
        if(memo[left][right] != 0)
            return memo[left][right];
        if(s[left] == s[right])
            memo[left][right] = (2 + palHelper(left+1, right-1, s, memo));
        else
            memo[left][right] = max(palHelper(left+1, right, s, memo), palHelper(left, right-1, s, memo));
        return memo[left][right];
    }
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<vector<int>> memo(size, vector<int>(size, 0));
        return palHelper(0, size-1, s, memo);
    }
};