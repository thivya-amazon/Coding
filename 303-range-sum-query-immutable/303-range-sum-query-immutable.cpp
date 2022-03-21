class NumArray {
public:
    vector<int> prefixSums;
    void populatePrefixSum(vector<int>& nums)
    {
        int prefixSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            prefixSums.push_back(prefixSum);
        }
    }
    NumArray(vector<int>& nums) {
        populatePrefixSum(nums);
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
            return prefixSums[right];
        return prefixSums[right] - prefixSums[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */