class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        int count = 0;
        unordered_map<int, int> umap;
        for(auto i : nums1)
            for(auto j : nums2)
            {
                umap[i+j]++;
            }
        
        for(auto k : nums3)
            for(auto l : nums4)
            {
                int sum = k + l;
                if(umap.find(-sum) != umap.end())
                    count += umap[-sum];
            }
        return count;
        
    }
};