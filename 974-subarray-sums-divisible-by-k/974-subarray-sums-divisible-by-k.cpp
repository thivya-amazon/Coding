class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int globalCount = 0;
        int prefixSum = 0;
        unordered_map<int,int> umap;
        umap[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            prefixSum = (prefixSum + nums[i]) % k;
            if(prefixSum < 0)
                prefixSum += k;

            if(umap.find(prefixSum) != umap.end())
                globalCount += umap[prefixSum];

            if(umap.find(prefixSum) != umap.end())
                umap[prefixSum] += 1;
            else
                umap[prefixSum] = 1;
        }
        return globalCount;
    }
};