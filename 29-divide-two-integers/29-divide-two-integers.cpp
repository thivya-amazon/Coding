class Solution {
public:
    #define HALF_INT_MIN  (INT_MIN >> 1)
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        if(divisor == 1)
            return dividend;
        
        int sign = 1;
        if(dividend > 0 && divisor < 0)
            sign = -1;
        else if(dividend < 0 && divisor > 0)
            sign = -1;
        
        unsigned int udividend = abs(dividend);
        unsigned int udivisor = abs(divisor);
        
        unsigned int highestPowerOf2 = 1;
        unsigned int highestMultiple = udivisor;
        
        while(highestMultiple <= udividend && highestMultiple <= abs(HALF_INT_MIN))
        {
            highestPowerOf2 += highestPowerOf2;
            highestMultiple += highestMultiple;
        }
        int quotient = 0;
        
        while(udividend >= udivisor)
        {
            if(udividend >= highestMultiple)
            {
                quotient += highestPowerOf2;
                udividend -= highestMultiple;
            }
            highestPowerOf2 >>= 1;
            highestMultiple >>= 1;
        }
        
        return (sign * quotient);
    }
};