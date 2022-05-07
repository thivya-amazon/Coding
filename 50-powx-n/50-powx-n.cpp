class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n == INT_MIN)
        {
            if(x == 1 || x == -1)
                return 1;
            else
                return 0;
        }
        if(n < 0)
        {
            x = 1/x;
            n *= -1;
        }
        double halfPow = x;
        double result = 1;
        for(int i = n; i > 0; i=i/2)
        {
            if(i % 2 == 1)
                result = result * halfPow;
            halfPow = halfPow * halfPow;
        }
        return result;
    }
};