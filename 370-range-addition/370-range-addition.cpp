class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length, 0);
        for(int i = 0; i < updates.size(); i++)
        {
            int start = updates[i][0];
            int end = updates[i][1];
            int inc = updates[i][2];
            
            arr[start] += inc;
            if(end + 1 < length)
                arr[end+1] -= inc;
        }
        for(int i = 1; i < length; i++)
            arr[i] += arr[i-1];
            
        return arr;
    }
};