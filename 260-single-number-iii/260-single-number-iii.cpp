class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        uint32_t bitMask = 0;
        for(auto num : nums)
            bitMask ^= num;
        int x = 0;
        uint32_t diff = bitMask & (-bitMask);

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