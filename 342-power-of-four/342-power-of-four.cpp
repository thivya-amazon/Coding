class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n > 0 && ((n & (n-1)) == 0) && ((n & 0xaaaaaaaa) == 0))
            return true;
        return false;
    }
};