class Solution {
public:
    uint32_t reverseByte(uint32_t byte, map<uint32_t, uint32_t>& cache)
    {
        if(cache.find(byte) != cache.end())
        {
            cout << "byte : " << byte << " " << cache[byte]<<endl;
            return cache[byte];
        }
        uint32_t temp = byte;    
        uint32_t value = 0;
        int pos = 7;
        while(temp)
        {
            value += (temp & 1) << pos;
            temp = temp >> 1;
            pos--;
        }
        cout << "Ibyte : " << byte << " " << cache[byte]<<endl;
        cache[byte] = value;    
        return value;
    }
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0; 
        int pos = 24;
        map<uint32_t, uint32_t> cache;
        while(n)
        {
            uint32_t byte = n & 0xFF;
            result |= reverseByte(byte, cache) << pos;
            n = n >> 8;
            pos -= 8;
        }
        return result;
    }
};