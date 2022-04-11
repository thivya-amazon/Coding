class Solution {
public:
    int fib(int n) {
        if(n <= 1)
            return n;
    int first = 0;
    int second = 1;
        int next = 0;
        for(int i = 2; i <= n; i++)
        {
            next = first + second;
            first = second;
            second = next;
        }
        return next;
    }
};