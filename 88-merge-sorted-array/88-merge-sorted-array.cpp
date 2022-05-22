class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1Copy = nums1;
        nums1Copy.resize(m);
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < m && j < n)
        {
            if(nums1Copy[i] <= nums2[j])
            {
                nums1[k] = nums1Copy[i];
                i++;
                k++;               
            }
            else
            {
                nums1[k] = nums2[j];
                j++;
                k++;
            }
        }
        while(i < m)
            nums1[k++] = nums1Copy[i++];
        while(j < n)
            nums1[k++] = nums2[j++];
        return;
    }
};