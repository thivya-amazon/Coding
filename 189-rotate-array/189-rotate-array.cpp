class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for(int i = 0; i < nums.size(); i++)
        {
            int rotIdx = (i + k) % n;
            temp[rotIdx] = nums[i];
        }
        nums = temp;
            
    }
};