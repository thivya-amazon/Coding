class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> count(32, 0);
        int distance = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int bit = 0; bit < 32; bit++)
            {
                int mask = 1 << bit;
                if((nums[i] & mask) != 0)
                    count[bit]++;
            }
        }
        for(auto cnt : count)
        {
            distance += cnt * (nums.size() - cnt);
        }
        return distance;
    }
};