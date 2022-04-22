class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> umap;
        int count = 0;
        int maxLen = INT_MIN;
        int startIdx = 0;
        int left = 0;
        int right = 0;
        while(right < s.size())
        {
            umap[s[right]]++;
          
            while(umap.size() != 0 && umap.size() > k)
            {
                umap[s[left]]--;
                if(umap[s[left]] == 0)
                    umap.erase(s[left]);
                left++;                
            }
            maxLen = max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
        
    }
};