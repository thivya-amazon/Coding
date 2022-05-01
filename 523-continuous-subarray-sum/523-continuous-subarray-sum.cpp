class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
//         if(nums.size() < 2)
//             return false;
//         int prefixSum = nums[0];
//         unordered_map<int, bool> umap;
        
//         //Special case for k = 0
//         if(k == 0)
//         {
//             for(int i = 0; i < nums.size() - 1; i++)
//             {
//                 if(nums[i] == 0 && nums[i+1] == 0)
//                     return true;
//             }
//             return false;
//         }
        
//         //For a prefix sum of 0, there exists a subarray whose sum is a multiple of k
//         umap[0] = true;
        
//         //Since we don't want to include prefix subarrays of size 1, we start from index 1
//         for(int i = 1; i < nums.size(); i++)
//         {
//             int oldPrefixSum = prefixSum;
//             prefixSum = (oldPrefixSum + nums[i]) % k;
            
//             if(umap.find(prefixSum) != umap.end())
//                 return true;
//             //Since we don't want to have information of the immediate index before us, each manager adds the prev index's value to the hashmap              after calculating its local result
//             umap[oldPrefixSum] = true;
//         }
//         return false;
        
        	unordered_map<int, int> map;
	map[0] = -1;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (k != 0) {
			sum %= k;
		}
		if (map.find(sum) != map.end()) {
			if (i - map[sum] > 1) {
				return true;
			}
		} else {
			map[sum] = i;
		}
	}
	return false;
    }
};