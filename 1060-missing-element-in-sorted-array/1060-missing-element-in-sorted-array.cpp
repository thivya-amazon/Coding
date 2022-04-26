class Solution {
public:
    //Zones : | num Missing elems < k | numMissing elems >= k |
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            //Num of missing elems = actual value - expected value
            int missingElems = nums[mid] - (nums[0] + mid);
            if(missingElems < k)
                start = mid + 1;
            else
                end = mid - 1;
        }
        //At this point start will point to the last elem in left zone and start will point to the first elem in right zone
        //The missing element is between end and start
        //Calculate the number of missing elems at end
        int missing = nums[end] - (nums[0] + end);
        int kthMissing = nums[end] + (k - missing);
        return kthMissing;
    }
};