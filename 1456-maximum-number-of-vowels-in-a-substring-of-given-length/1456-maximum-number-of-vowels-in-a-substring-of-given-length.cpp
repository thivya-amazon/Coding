class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int maxNum = 0;
        int numVowels = 0;
        for(int i = 0; i < k; i++)
        {
            if(vowels.count(s[i]))
                numVowels++;
        }
        maxNum = numVowels;
        for(int i = k; i < s.size(); i++)
        {
            if(vowels.count(s[i]))
                numVowels++;
            if(vowels.count(s[i-k]))
                numVowels--;
            maxNum = max(maxNum, numVowels);
        }
        return maxNum;
    }
};