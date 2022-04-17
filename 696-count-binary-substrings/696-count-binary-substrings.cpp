class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0;
        int currConsecutiveSeq = 1;
        int lastConsecutiveSeq = 0;
        
        for(int i = 1; i < s.size(); i++)
        {
            //beginning of a new sequence
            if(s[i] != s[i-1])
            {
                lastConsecutiveSeq = currConsecutiveSeq;
                currConsecutiveSeq = 1;
                count++;
            }
            else
            {
                currConsecutiveSeq++;
                if(currConsecutiveSeq <= lastConsecutiveSeq)
                    count++;
            }
        }
        return count;
    }
};