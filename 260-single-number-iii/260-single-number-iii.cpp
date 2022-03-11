class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        int bitMask = 0;
        for(auto num : nums)
            bitMask ^= num;
        int x = 0;
        int diff = 0;
        for(int i = 0; i < 32; i++)
        {
            if(bitMask & (1 << i))
            {
                diff = bitMask & (1 << i);
                break;
            }               
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] & diff)
                x ^= nums[i];
        }
                    
        int y = bitMask ^ x;
        result.push_back(x);
        result.push_back(y);
        return result;
    }
};