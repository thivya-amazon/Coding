class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN;
        int windowSum = 0;
        for(int i = 0; i < k; i++)
        {
            windowSum += nums[i];
        }
        maxAvg = max(maxAvg, (double)windowSum / k);
        for(int i = k; i < nums.size(); i++)
        {
            windowSum += nums[i] - nums[i-k];
            maxAvg = max(maxAvg, (double)windowSum/k);
        }
        return maxAvg;
    }
    
};