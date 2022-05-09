class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque;    //To keep track of max val in subarray
        deque<int> minDeque;    //To keep track of min val in subarray
        int left = 0;
        int maxLength = 0;
        for(int right = 0; right < nums.size(); right++)
        {
            //insert nums[right] into both the deques
            while(!maxDeque.empty() && maxDeque.back() < nums[right])
                maxDeque.pop_back();
            maxDeque.push_back(nums[right]);
            
            while(!minDeque.empty() && minDeque.back() > nums[right])
                minDeque.pop_back();
            minDeque.push_back(nums[right]);
            
           // range = maxDeque.front() - minDeque.front();
            
            while(left <= right && (maxDeque.front() - minDeque.front()) > limit)
            {
                //Remove the left element from the window
                if(nums[left] == maxDeque.front())
                    maxDeque.pop_front();
                if(nums[left] == minDeque.front())
                    minDeque.pop_front();
                left++;
            }
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};