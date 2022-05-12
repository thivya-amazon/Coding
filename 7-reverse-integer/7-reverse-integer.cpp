class Solution {
public:
    int reverse(int x) { 
        int sign = 1;
        // if(x < 0)
        //     sign = -1;
        // x = abs(x);
        int result = 0;
        while(x)
        {
            if(result > INT_MAX/10 || (result == INT_MAX/10 && (x % 10 > 7)))
                return 0;
            if(result < INT_MIN/10 || (result == INT_MIN/10 && (x % 10 < -8)))
                return 0;
            result = (result*10) + (x % 10);
            x = x / 10;
        }
       return result * sign;
                    
    }
};