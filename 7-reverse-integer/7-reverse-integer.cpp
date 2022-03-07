class Solution {
public:
    int reverse(int x) {
        bool positive = true;
        if(x < 0)
           positive = false; 
        int result = 0;
      //  x = abs(x);
        while(x)
        {
            if(result > INT_MAX/10)
                return 0;
            if(result < INT_MIN/10)
                return 0;
            result = (result*10) + (x % 10);
            x = x / 10;
        }
       return result;
                    
    }
};