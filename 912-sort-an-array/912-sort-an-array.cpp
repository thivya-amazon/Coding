class Solution {
public:
    int getPivotIndex(vector<int>& nums, int start, int end)
    {
        srand(NULL);
        int randIndex = start + rand() % (end - start);
        swap(nums[randIndex], nums[start]);
        
        int pivot = nums[start];
        int smaller = start;
        int bigger = start;
        for(; bigger <= end; bigger++)
        {
            if(nums[bigger] < pivot)
            {
                smaller++;
                swap(nums[smaller], nums[bigger]);
            }
        }
        swap(nums[start], nums[smaller]);
        return smaller;
    }
    void quickSort(vector<int>& nums, int start, int end)
    {
        if(start >= end)
            return;
        int pivotIndex = getPivotIndex(nums, start, end);
        quickSort(nums, start, pivotIndex-1);
        quickSort(nums, pivotIndex+1, end);        
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n-1);
        return nums;
    }
};