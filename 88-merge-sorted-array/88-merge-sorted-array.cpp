class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1Copy = nums1;
        nums1Copy.resize(m);
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(k >= 0)
        {
            if (j < 0)
                break;
            if(i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
                k--;               
            }
            else 
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
        return;
    }
};