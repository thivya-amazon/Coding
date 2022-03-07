class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) 
            return true;
        int left = 0;
        int right = 0;
        while(right < t.size())
        {
            if(s[left] == t[right])
            {
                left++;
                right++;
            }
            else
                right++;
        }
        if(left == s.size())
            return true;
        
        return false;
    }
};