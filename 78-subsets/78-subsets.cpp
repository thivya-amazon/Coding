class Solution {
public:
    vector<vector<int>> result;
    void subsetHelper(int sub_idx, vector<int>& slate, vector<int>& nums)
    {
        if(sub_idx == nums.size())
        {
            result.push_back(slate);
            return;
        }
        //inclusion
        slate.push_back(nums[sub_idx]);
        subsetHelper(sub_idx+1, slate, nums);
        slate.pop_back();
        
        //exclusion
        subsetHelper(sub_idx+1, slate, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> slate;
        subsetHelper(0, slate, nums);
        return result;
    }
};