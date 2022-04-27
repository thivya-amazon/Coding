class Solution {
public:
    int arrangeCoins(int n) {
        long used = 0;
        int i;
        for(i = 1; i <= n; i++)
        {
            if(used + i <= n)
                used += i;
            else
                break;
        }
        // if(n == used)
        //     return i;
        // else
            return i-1;
    }
};