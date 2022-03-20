class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int local = 1;
        int global = INT_MIN;
        
        for(auto num : nums)
        {
            local *= num;
            global = max(global, local);
            if(local == 0)
                local = 1;
        }
        local = 1;
        for(int i = nums.size()-1; i >= 0; i--)
        {
            local *= nums[i];
            global = max(global, local);
            if(local == 0)
                local = 1;
        }
        return global;
    }
};