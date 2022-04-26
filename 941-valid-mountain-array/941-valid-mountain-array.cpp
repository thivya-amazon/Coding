class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i;
        int j;
        if(arr.size() < 3)
            return false;
        for(i = 0; i < arr.size()-2; i++)
        {
            if(arr[i] >= arr[i+1])
                break;
        }
        for(j = arr.size()-1; j > 1; j--)
        {
            if(arr[j] >= arr[j-1])
                break;
        }
        return i==j;
    }
};