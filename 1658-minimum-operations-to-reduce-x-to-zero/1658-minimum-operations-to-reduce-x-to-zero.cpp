class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for(auto n : nums)
            totalSum += n;
        //In order to minimize the number of array elements adding up to x, we can maximize the elements making k
        int k = totalSum - x;
        
        int left = 0;
        int windowSum = 0;
        int maxLength = INT_MIN;
        for(int right = 0; right < nums.size(); right++)
        {
            windowSum += nums[right];
            
            while(left <= right && windowSum > k)
            {
                windowSum -= nums[left];
                left++;
            }
            if(windowSum == k)
                maxLength = max(maxLength, right-left+1);
        }
        if(maxLength == INT_MIN)
            return -1;
        return nums.size()-maxLength;
    }
};