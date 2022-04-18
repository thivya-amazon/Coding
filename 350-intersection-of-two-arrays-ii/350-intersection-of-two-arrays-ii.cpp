class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = (n1 > n2) ? n1 : n2;
        if(n2 > n1)
        {
            vector<int> temp = nums2;
            nums2 = nums1;
            nums1 = temp;
        }
        unordered_map<int, int> mp1(n);
        unordered_map<int, int> mp2(n);
        
        //Update mp for nums1
        for(int i = 0; i < nums1.size(); i++)
        {
            mp1[nums1[i]]++;
        }
        
        for(int i = 0; i < nums2.size(); i++)
        {
            mp2[nums2[i]]++;
        }
        
        for(int i = 0; i < n; i++)
        {
            mp1[nums1[i]] = min(mp1[nums1[i]], mp2[nums1[i]]);
        }
        for(int i = 0; i < n; i++)
        {
            if(mp1[nums1[i]] > 0)
            {
                int count = mp1[nums1[i]];
                while(count--)
                {
                    result.push_back(nums1[i]);
                }
                mp1[nums1[i]] = 0;
            }
        }
        return result;
    }
};