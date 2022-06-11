class Solution {
public:
    int strStr(string haystack, string needle) {
        int hIndex = 0;
        int nIndex = 0;

        if(needle.size() > haystack.size())
            return -1;
        while(hIndex < haystack.size())
        {
            if(haystack[hIndex] == needle[nIndex])
            {
                nIndex++;
            }
            else
            {
                hIndex = hIndex - nIndex;
                nIndex = 0;
            }
            if(nIndex == needle.size())
                return (hIndex - nIndex + 1);
             hIndex++;   
        }
        return -1;
    }
};