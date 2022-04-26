/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int start = 1;
        int end = n - 2;
        int peakIndex = 0;
        //Edge case: Target is the first element
        if(mountainArr.get(0) == target)
            return 0;
        
        //BS1 : Find the peak index
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int midElem = mountainArr.get(mid);
            int prevElem = mountainArr.get(mid-1);
            int nextElem = mountainArr.get(mid+1);
            if(midElem > prevElem && midElem > nextElem)
            {
                 peakIndex = mid;
                break;
            }               
            else if(midElem > prevElem)
                start = mid + 1;
            else
                end = mid - 1;
        }
        
        if(mountainArr.get(peakIndex) == target)
            return peakIndex;
        //BS2 : Find the target in the ascending zone
        start = 1;
        end = peakIndex - 1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int midElem = mountainArr.get(mid);
            if(midElem == target)
                return mid;
            if(midElem < target)
                start = mid+1;
            else
                end = mid-1;                
        }
        
        //BS3 : Find the target in the descending zone
        start = peakIndex + 1;
        end = mountainArr.length() - 1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int midElem = mountainArr.get(mid);
            if(midElem == target)
                return mid;
            if(midElem < target)
                end = mid-1;
            else
                start = mid+1;                
        }
        
        return -1;
    }
};