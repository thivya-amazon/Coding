class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        vector<int> result;
        
        int diff = s1.size() - s2.size();
        if(diff >= 0)
        {
            for(auto num : s2)
                if(s1.count(num))
                    result.push_back(num);
        }
        else
        {
            for(auto num : s1)
                if(s2.count(num))
                    result.push_back(num);
        }
        return result;    
    }
};