class Solution {
public:
    int helper(int i, vector<int>& nums)
    {
        int nxt = (i + nums[i]);
        if(nxt < 0)
            nxt = (nums.size() + nxt) % nums.size();
        else
            nxt = nxt % nums.size();
        return nxt;
    }
    bool circularArrayLoop(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            int fast = i;
            int slow = i;
            while(true)
            {
                fast = helper(fast, nums);
                fast = helper(fast, nums);
                slow = helper(slow, nums);
                
                //loop detected
                if(slow == fast)
                {
                    int third = slow;
                    bool positive = nums[third] > 0 ? true : false;
                    int count = 1;
                    while(helper(third, nums) != slow)
                    { 
                        third = helper(third, nums);
                        count++;
                        if((positive && nums[third] < 0) || (!positive && nums[third] > 0))
                        {
                            count = 1;
                            break;
                        }
                    }
                    if(count > 1)
                        return true;
                    else
                    {
                       break;                        
                    }
                }
            }
        }
        return false;
    }
};