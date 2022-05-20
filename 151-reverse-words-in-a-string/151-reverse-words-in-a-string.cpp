class Solution {
public:
    void revword(string& s, int start, int end)
    {
        while(start < end)
        {
            swap(s[start++], s[end--]);
        }
    }
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int startIdx = 0;
        int endIdx = s.size() - 1;
        
        int index = startIdx;
        while(index < s.size())
        {
            int j = index;
            //Skip leading spaces
            while(j < s.size() && isspace(s[j]))
                j++;
            
            //Count the number of letters in a word
            int count = 0;
            while(j < s.size() && !isspace(s[j]))
            {
                j++;
                count++;
            }
            
            if(index == 0)
                revword(s, index, j-1);
            else
                revword(s, index+1, j-1);
            
            
            if(count == 0)
                index = j;
            else
                index = index + count;
        }
        while(isspace(s[endIdx]))
        {
            s.pop_back();
            endIdx--;
        }
            
        return s;
    }
};