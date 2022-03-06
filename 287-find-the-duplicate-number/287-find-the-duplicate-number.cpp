class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(true)
        {
            fast = nums[fast];
            fast = nums[fast];
            slow = nums[slow];
            
            if(slow == fast)
            {
                int newSlow = 0;
                while(newSlow != slow)
                {
                    slow = nums[slow];
                    newSlow = nums[newSlow];
                }
                return slow;
            }
        }
        return -1;
    }
};