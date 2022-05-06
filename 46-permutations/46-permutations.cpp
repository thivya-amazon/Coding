class Solution {
public:
    vector<vector<int>> result;
    void permHelper(int sub_idx, vector<int> nums)
    {
        if(sub_idx == nums.size())
        {
            result.push_back(nums);
            return;
        }
        for(int i = sub_idx; i < nums.size(); i++)
        {
            swap(nums[i], nums[sub_idx]);
            permHelper(sub_idx+1, nums);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permHelper(0, nums);
        return result;
    }
};