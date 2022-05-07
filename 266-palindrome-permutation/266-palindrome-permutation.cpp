class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> charMap(26, 0);
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            charMap[s[i]-'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            count += (charMap[i] % 2);
        }
        return count <= 1;
    }
};