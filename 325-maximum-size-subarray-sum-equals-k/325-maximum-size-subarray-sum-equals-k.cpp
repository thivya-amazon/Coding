class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int maxLength = 0;
        int prefixSum = 0;
        //Stores prefix sum of subarray as key and its length as value
        unordered_map<int,int> umap;

        for(int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            if(prefixSum == k)
                maxLength = max(maxLength, i+1);
            
            if(umap.find(prefixSum - k) != umap.end())
                maxLength = max(maxLength, (i+1) - umap[prefixSum - k]);
            
            if(umap.find(prefixSum) == umap.end())
                umap[prefixSum] = i+1;
        }
        return maxLength;
    }
};