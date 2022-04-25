class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        vector<int> result;
        int n = nums.size();
        if(n == 1)
            return nums;
        for(auto n : nums)
            umap[n]++;
        for(auto m : umap)
        {
            if(m.second > n/3)
                result.push_back(m.first);
        }
        return result;
    }
};