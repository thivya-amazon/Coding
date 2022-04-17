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
        //Erase leading whitespaces
        while(isspace(s[start_idx]) && s[start_idx] != NULL)
        {
            s.erase(s.begin() + start_idx);
        }
        
        int end_idx = s.size()-1;
        //Erase trailing whitespaces
        while(isspace(s[end_idx]) && s[end_idx] != NULL)
        {
            s.erase(s.begin() + end_idx);
            end_idx--;
        }
        int index = 0;
        while(index < s.size())
        {
            int wordStart = index;
            while(isspace(s[wordStart]))
            {
                s.erase(s.begin()+wordStart);
            }
                
            while(!isspace(s[index]) && s[index] != NULL)
            {
                index++;
            }
                
            revWord(s, wordStart, index-1);
            //skip the white space and make the index point the start of the next word
            index++;
        }
        return s;
    }
};