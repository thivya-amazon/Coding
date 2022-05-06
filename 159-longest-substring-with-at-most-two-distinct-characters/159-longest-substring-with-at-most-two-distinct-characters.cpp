class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int maxLength = 0;
        unordered_map<char, int> distinctChars;
        int left = 0;
        
        for(int right = 0; right < s.size(); right++)
        {
            if(distinctChars.count(s[right]))
                distinctChars[s[right]]++;
            else
                distinctChars[s[right]] = 1;
            
            while(left <= right && distinctChars.size() > 2)
            {
                distinctChars[s[left]]--;
                if(distinctChars[s[left]] == 0)
                    distinctChars.erase(s[left]);
                left++;
            }
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};