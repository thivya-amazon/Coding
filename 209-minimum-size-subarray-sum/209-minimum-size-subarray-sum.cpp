class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX;
        int left = 0;
        int windowSum = 0;
        for(int  right = 0; right < nums.size(); right++)
        {
            windowSum += nums[right];
            
            while(left <= right && windowSum >= target)
            {
                minLength = min(minLength, right-left+1);
                //shrink the window
                windowSum -= nums[left];
                left++;
            }
        }
        return minLength==INT_MAX ? 0 : minLength;
    }
};