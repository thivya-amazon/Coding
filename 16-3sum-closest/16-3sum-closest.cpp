class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return -1;
        sort(nums.begin(), nums.end());
        int minDelta = INT_MAX;
        for(int i = 0; i < nums.size()-2; i++)
        {
            int lp = i+1;
            int rp = nums.size()-1;
            while(lp < rp)
            {
                int sum = nums[i] + nums[lp] + nums[rp];
                int delta = (target - sum);
                if(abs(delta) < abs(minDelta))
                    minDelta = delta;
                if(sum > target)
                    rp--;
                else
                    lp++;
            }

        }
        return (target-minDelta);
        
    }
};