class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2)
            return false;
        int prefixSum = 0;
        unordered_map<int, int> umap;
        
        //Special case for k = 0
        if(k == 0)
        {
            for(int i = 0; i < nums.size() - 1; i++)
            {
                if(nums[i] == 0 && nums[i+1] == 0)
                    return true;
            }
            return false;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            prefixSum = (prefixSum + nums[i]) % k;
            
            if(prefixSum == 0 && i)
                return true;
            
            if(umap.find(prefixSum) != umap.end())
            {
                if(i - umap[prefixSum] > 1)
                    return true;
            }
            else
                umap[prefixSum] = i;
        }
        return false;
        
    }
};