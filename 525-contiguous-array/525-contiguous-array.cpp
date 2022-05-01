class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        int prefixSum = 0;
        unordered_map<int, int> umap;
        umap[0] = 0;
        //Replace all 0s with -1s - Convert the problem to maximum subarray length with sum 0
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                nums[i] = -1;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            if(umap.find(prefixSum - 0) != umap.end())
                maxLength = max(maxLength, i+1 - umap[prefixSum - 0]);
            else
                umap[prefixSum] = i+1;                
        }
        return maxLength;
        
    }
};