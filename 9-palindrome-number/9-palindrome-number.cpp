class Solution {
public:
    unsigned int reverse(int x)
    {
        unsigned int revNum = 0;
        while(x)
        {
            revNum = revNum * 10 + (x % 10);
            x /= 10;
        }
        return revNum;
    }
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int revNum = reverse(x);
        if(x == revNum)
            return true;
        return false;
    }
};