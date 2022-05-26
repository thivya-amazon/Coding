class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int globalCount = 0;
        int prefixSum = 0;
        unordered_map<int, int> umap;
        umap[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            //1. Find prefix sum
            prefixSum += nums[i];
            
            //2. For a given suffix, look for the corresponding prefix in the hashmap
            if(umap.find(prefixSum - k) != umap.end())
                globalCount += umap[prefixSum - k];
            
            //3. Update hashmap with the current prefix
            umap[prefixSum]++;         
        }
        return globalCount;
    }
};