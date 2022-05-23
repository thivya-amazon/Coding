class Solution {
public:
    int helper(int n)
    {
        int total = 0;
        while(n)
        {
            total += pow((n % 10), 2);
            n /= 10;
        }
        return total;
    }
    bool isHappy(int n) {
        int fast = n;
        int slow = n;
        while(true)
        {
            fast = helper(fast);
            fast = helper(fast);
            slow = helper(slow);
            if(fast == slow)
                break;
        }
        return slow == 1;
    }
};