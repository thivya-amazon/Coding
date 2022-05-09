class Solution {
public:
    int helper(int x)
    {
        long total = 0;
        while(x)
        {
            total += pow(x%10, 2);
            x /= 10;
        }
        return total;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        
        while(true)
        {
            slow = helper(slow);
            fast = helper(fast);
            fast = helper(fast);
            if(slow == fast)
                return slow == 1;
        }
    }
};