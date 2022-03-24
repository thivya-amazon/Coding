class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //Find all the next greater elements for each elemet in nums2 and store it in a map
        unordered_map<int, int> umap;
        stack<int> mono;
        vector<int> result(nums1.size(), -1);
        for(int i = nums2.size()-1; i >= 0; i--)
        {
            while(!mono.empty() && mono.top() <= nums2[i])
                mono.pop();
            if(!mono.empty())
                umap[nums2[i]] = mono.top();
            mono.push(nums2[i]);
        }
        //For each element in nums1, check if there is a greater element in umap
        for(int j = 0; j < nums1.size(); j++)
        {
           if(umap.find(nums1[j]) != umap.end())
               result[j] = umap[nums1[j]];
        }
        return result;
    }
};