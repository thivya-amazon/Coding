class Solution {
public:
    int getSum(int a, int b) {
        
        while(b != 0)
        {
            int sum = a ^ b;
            unsigned int carry = a & b;
            a = sum;
            b = carry << 1;
        }
        return a;
    }
};