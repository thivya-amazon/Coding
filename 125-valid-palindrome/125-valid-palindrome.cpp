class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0)
            return true;
        string letters;
        for(int i = 0; i < s.size(); i++)
        {
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            {
                s[i] = tolower(s[i]);
            }
            else
            {
                s.erase(s.begin() + i);
                i--;
            }
        }
       int start = 0;
        int end = s.size()-1;
        while(start < end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};