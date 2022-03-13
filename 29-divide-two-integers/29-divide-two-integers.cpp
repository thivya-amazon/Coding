class Solution {
public:
    int divide(int dividend, int divisor) {
    
        int halfMinInt = INT_MIN >> 1;
    //INT_MIN does not have a positive counterpart
    if(dividend == INT_MIN && divisor == -1)
        return INT_MAX;
        
    //Convert both operands to negative values since they have a better range than positive values
    int numNegatives = 2;
        if(dividend > 0)
        {
            numNegatives--;
            dividend = -dividend;
        }
        if(divisor > 0)
        {
            numNegatives--;
            divisor = -divisor;
        }
        
    //Find the highest power of 2 that would fit in the dividend
    int highestPowerOf2 = -1;
    int highestDouble = divisor;
        //Since we are operating on negative numbers, less than implies within the value
        while(dividend <= highestDouble && highestDouble >= halfMinInt)
        {
            highestPowerOf2 += highestPowerOf2;
            highestDouble += highestDouble;
        }
        
        int quotient = 0;
        while(dividend <= divisor)
        {
            if(dividend <= highestDouble)
            {
                quotient += highestPowerOf2;
                dividend -= highestDouble;
            }
            
            highestPowerOf2 >>= 1;
            highestDouble >>= 1;
        }
        if(numNegatives != 1)
        {
            return -quotient;
        }
        return quotient;
    }
};