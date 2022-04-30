//What are we trying to maximize?
//Find a range for this value we are trying to optimize
//Zones :  | cap too low, days taken > days | cap too high, days taken <= days |

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //Find the range for the value to optimize
        int maxWeight = INT_MIN;
        int totalWeight = 0;
        for(int i = 0; i < weights.size(); i++)
        {
            maxWeight = max(maxWeight, weights[i]);
            totalWeight += weights[i];
        }
        int start = maxWeight;
        int end = totalWeight;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int weightSoFar = 0;
            //Find the number of days to ship for the chosen capacity of the ship
            int numDays = 1;            
            for(int i = 0; i < weights.size(); i++)
            { 
                 weightSoFar += weights[i];
                if(weightSoFar > mid)
                {
                   weightSoFar = weights[i];
                    numDays++;
                }                               
            }
            if(numDays > days)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return start;
    }
};