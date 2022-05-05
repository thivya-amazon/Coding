class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxOnes = 0;
        int numZeros = 0;
        int left = 0;
        for(int right = 0; right < nums.size(); right++)
        {
            if(nums[right] == 0)
                numZeros++;
            while(left <= right && numZeros > k)
            {
                if(nums[left] == 0)
                    numZeros--;
                left++;
            }
            maxOnes = max(maxOnes, right-left+1);
        }
        return maxOnes;
    }
};