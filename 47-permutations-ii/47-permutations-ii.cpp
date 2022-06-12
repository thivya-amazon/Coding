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
            if(i == sub_idx || ((nums[i] != nums[i-1] && nums[i] != nums[sub_idx])))
            {
                swap(nums[i], nums[sub_idx]);
                permHelper(sub_idx+1, nums);
                //swap(nums[i], nums[sub_idx]);
            }
        }
    }

vector<vector<int>> permuteUnique(vector<int>& nums) {        
        sort(nums.begin() , nums.end());
        permHelper(0, nums);
        return result;
    }
};