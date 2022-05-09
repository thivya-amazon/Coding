class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap;
        int left = 0;
        int count = 0;
        int minLen = INT_MAX;
        int startIdx = -1;
        
        for(int i = 0; i < t.size(); i++)
            tmap[t[i]]++;
        
        count = tmap.size();
        for(int right = 0; right < s.size(); right++)
        {
            tmap[s[right]]--;
            if(tmap[s[right]] == 0)
                count--;
            if(count == 0)
            {
                while(count == 0)
                {
                    if(right-left+1 < minLen)
                    {
                        minLen = right - left + 1;
                        startIdx = left;
                    }
                    
                    //Shrink the window from the left
                    tmap[s[left]]++;
                    if(tmap[s[left]] > 0)
                        count++;                   
                    left++;
                }
            }            
        }
        if (minLen == INT_MAX)
            return "";
        return s.substr(startIdx, minLen);
    }
};