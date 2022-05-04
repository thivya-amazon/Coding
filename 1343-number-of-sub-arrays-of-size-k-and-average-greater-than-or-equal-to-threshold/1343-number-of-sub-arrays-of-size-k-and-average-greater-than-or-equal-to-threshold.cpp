class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        float currAvg = 0.0;
        int currSum = 0;
        for(int i = 0; i < k; i++)
            currSum += arr[i];
        currAvg = (float)currSum/k;
        if(currAvg >= threshold)
            count++;
        
        for(int i = k; i < arr.size(); i++)
        {
            currSum = currSum + arr[i] - arr[i-k];
            currAvg = currSum/k;
            if(currAvg >= threshold)
                count++;
        }
        return count;
            
    }
};