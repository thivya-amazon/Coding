class Solution {
public:
    
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0; 
        int pos = 31;
        while(n)
        {
            result |= (n & 1) << pos;
            n = n >> 1;
            pos--;
        }
        return result;
    }
};