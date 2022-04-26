class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        //Find the common difference for the series
        int d  = 0;
        if(arr[1] > arr[0])
            d = min(arr[1]-arr[0], arr[n-1]-arr[n-2]);
        else
           d = max(arr[1]-arr[0], arr[n-1]-arr[n-2]); 
        
        int start = 0;
        int end = n-1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(arr[mid] == arr[0] + mid*d)
                start = mid + 1;
            else
                end = mid - 1;
        }
        //When you let the search fail, at this point start>end and the boundary between the zones will be between start & end
        return arr[end]+d;
    }
};