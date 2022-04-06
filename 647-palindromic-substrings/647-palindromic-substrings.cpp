class Solution {
public:
    int expandAroundCenter(string s, int left, int right)
    {
        int count = 0;
        while(left >= 0 && right < s.size())
        {
            if(s[left] != s[right])
                break;
            left--;
            right++;
            count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        if(s.size() <= 1)
            return s.size();

        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            count += expandAroundCenter(s, i, i);
            count += expandAroundCenter(s, i, i+1);
        }
        return count;
    }
};