class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int globalCount = 0;
        int windowProd = 1;
        int left = 0;
        for(int right = 0 ; right < nums.size(); right++)
        {
            windowProd *= nums[right];
            while(left <= right && windowProd >= k)
            {
                //Shrink the window
                windowProd /= nums[left];
                left++;
            }
            //When we exit the while loop, windowProd is less than k
            //So, all the subarray within that window will have a product less than k
            globalCount += right - left + 1;
        }
        return globalCount;
    }
};