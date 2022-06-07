class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int abbPtr = 0;
        int wordPtr = 0;
        int num = 0;
        for(; abbPtr < abbr.size(); abbPtr++)
        {
            if(isdigit(abbr[abbPtr]))
            {
                if(abbr[abbPtr] == '0' && num == 0)
                    return false;
                num = num * 10 + (abbr[abbPtr] - '0');
            }
            else
            {
                wordPtr += num;
                num = 0;
                if(wordPtr >= word.size() || word[wordPtr] != abbr[abbPtr])
                    return false;
                wordPtr++;
            }

        }
        wordPtr += num;
        return wordPtr == word.size();
    }
};