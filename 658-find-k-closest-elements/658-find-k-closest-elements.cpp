class Solution {
public:
    int findIndex(vector<int>& arr, int start, int end, int val)
    {
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(arr[mid] == val)
                return mid;
            if(arr[mid] < val)
                start = mid+1;
            else
                end = mid-1;
        }
        return end;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int index = findIndex(arr, 0, arr.size()-1, x);
        
        int startIndex = max(0, index-k);
        int endIndex = min(index+k, n-1);
        
        while(endIndex - startIndex >= k)
        {
            if(abs(arr[startIndex] - x) <= abs(arr[endIndex] - x))
                endIndex--;
            else
                startIndex++;
        }
        for(int i = startIndex; i <= endIndex; i++)
            result.push_back(arr[i]);
        return result;
    }
};