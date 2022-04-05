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
                letters.push_back(tolower(s[i]));
            }                
        }
       int start = 0;
        int end = letters.size()-1;
        while(start < end)
        {
            if(letters[start++] != letters[end--])
                return false;
        }
        return true;
    }
};