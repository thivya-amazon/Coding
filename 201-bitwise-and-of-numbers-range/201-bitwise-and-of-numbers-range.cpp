class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
    //Find the common prefix of the start and end of the range   
    int shiftCount = 0;
        while(left != right)
        {
            left >>= 1;
            right >>= 1;
            shiftCount++;
        }
        while(shiftCount)
        {
            left <<= 1;
            shiftCount--;
        }
        return left;
    }
};