class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int globalCount = 0;
        int prefixSum = 0;
        int oddCount = 0;
        int evenCount = 1; //For prefixSum of 0
        
        for(int i = 0; i < arr.size(); i++)
        {
            prefixSum += arr[i];
            //odd prefix + even suffix = odd sum
            if(prefixSum % 2)
            {
                globalCount = (globalCount + evenCount) % 1000000007;
                oddCount++;
            }
                
            else
            {
                 globalCount = (globalCount + oddCount) % 1000000007;
                evenCount++;
            }               
        }
        return globalCount;
    }
};