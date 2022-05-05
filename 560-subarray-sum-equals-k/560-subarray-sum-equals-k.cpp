class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int globalCount = 0;
        int prefixSum = 0;
        unordered_map<int, int> umap;
        umap[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            
            // if(prefixSum == k)
            //     globalCount += 1;
            
            if(umap.find(prefixSum - k) != umap.end())
                globalCount += umap[prefixSum - k];
            
            if(umap.find(prefixSum) != umap.end())
                umap[prefixSum] += 1;
            else
                umap[prefixSum] = 1;            
        }
        return globalCount;
    }
};