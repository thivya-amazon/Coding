// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       int start = 1;
        int end = n;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            // if(isBadVersion(mid) == true && isBadVersion(mid-1) == false)
            //     return mid;
            // else if(isBadVersion(mid) == false && isBadVersion(mid+1) == true)
            //     return mid+1;
            if(isBadVersion(mid) == true)
                end = mid-1;
            else
                start = mid+1;
        }
        return start;
    }
};