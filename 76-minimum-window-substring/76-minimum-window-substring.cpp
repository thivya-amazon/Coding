class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> umap;
        
        //Insert all characters in t into a map
        for(int i = 0; i < t.size(); i++)
            umap[t[i]]++;
        
        int left= 0;
        int right = 0;
        int startIdx = 0;
        int minLen = INT_MAX;
        int count = umap.size();
        while(right < s.size())
        {
            umap[s[right]]--;
            if(umap[s[right]] == 0)
                count--;
            if(count == 0)
            {
                while(count == 0)
                {
                    if(right-left+1 < minLen)
                    {
                        minLen = right-left+1;
                        startIdx = left;
                    }
                
                    umap[s[left]]++;
                    if(umap[s[left]] > 0)
                        count++;
                    left++;
                }
            }
            right++;
        }
        
        if(minLen == INT_MAX)
            return "";
        return s.substr(startIdx, minLen);

    }
};