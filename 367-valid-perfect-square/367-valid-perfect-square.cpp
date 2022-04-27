class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 0;
        int end = num;
        while(start <= end)
        {
            long mid = start + (end-start)/2;
            if(mid*mid == num)
                return true;
            if(mid*mid < num)
                start = mid+1;
            else
                end = mid-1;
        }
        return false;
    }
};