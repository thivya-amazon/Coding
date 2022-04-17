class Solution {
public:
    void revWord(string& s, int start, int end)
    {
        while(start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        int start_idx = 0;
        while(isspace(s[start_idx]) && s[start_idx] != NULL)
        {
            s.erase(s.begin() + start_idx);
        }
        
        int end_idx = s.size()-1;
        while(isspace(s[end_idx]) && s[end_idx] != NULL)
        {
            s.erase(s.begin() + end_idx);
            end_idx--;
        }
        start_idx = 0;
        end_idx = 0;
        while(end_idx < s.size())
        {
            int wordStart = start_idx;
            while(isspace(s[wordStart]))
            {
                s.erase(s.begin()+wordStart);
                //wordStart++; 
            }
                
            while(!isspace(s[start_idx]) && s[start_idx] != NULL)
            {
               end_idx++;
                start_idx++;
            }
                
            revWord(s, wordStart, end_idx-1);
            start_idx = end_idx+1;
            end_idx = start_idx;
        }
        return s;
    }
};