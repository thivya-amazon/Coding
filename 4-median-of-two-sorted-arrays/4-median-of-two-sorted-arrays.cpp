class Solution {
public:
    int get(vector<int>& nums, int idx)
    {
        if(idx < 0)
            return INT_MIN;
        if(idx >= nums.size())
            return INT_MAX;
        return nums[idx];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        // if(m < n)
        //     return findMedianSortedArrays(nums2, nums1);
        int k = 0;
        //m+n = odd
        if((m+n) % 2 == 1)
            k = (m+n)/2 + 1;
        else
            k = (m+n)/2;
        int start = 0;
        int end = m-1;
        int kthSmallest = 0;
        int succ = 0;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            //Find if nums[mid] is the kth smallest element
            if(get(nums1, mid) >= get(nums2, k-1-mid-1) && get(nums1, mid) <= get(nums2, k-1-mid))
            {
                kthSmallest = get(nums1, mid);
                succ = min(get(nums1, mid+1), get(nums2, k-1-mid));
                break;
            }
                
            else if(get(nums1, mid) > get(nums2, k-1-mid))
                end = mid - 1;
            else if(get(nums1, mid) < get(nums2, k-1-mid-1))
                start = mid + 1;
        }
        
        //Unsuccesful binary search - kth smallest is not in nums1
        if(start == end+1)
        {
            kthSmallest = get(nums2, k-start-1);
            succ = min(get(nums2, k-start), get(nums1, start));
        }
        
        if((m+n) % 2 == 1)
            return kthSmallest;
        return (kthSmallest + succ) /2.0;
        
    }
};