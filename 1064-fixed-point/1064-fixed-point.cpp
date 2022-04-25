class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(arr[mid] < mid)
                start = mid+1;
            else
                end = mid-1;
        }
        if(start < arr.size() && arr[start] == start)
            return start;
        return -1;
    }
};