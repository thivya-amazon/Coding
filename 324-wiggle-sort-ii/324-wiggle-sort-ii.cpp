class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        //All elements larger than median go into odd indices
        int index = 1;
        for(int i = n-1; i > (n-1)/2; i--)
        {
            nums[index] = sortedNums[i];
            index += 2;
        }
        
         //All elements smaller than median go into even indices
        index = 0;
        for(int i = (n-1)/2; i >= 0; i--)
        {
            nums[index] = sortedNums[i];
            index += 2;
        }
        return;
    }
};