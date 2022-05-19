class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0;
        int currTank = 0;
        int startIdx = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            totalTank += gas[i] - cost[i];
            currTank += gas[i] - cost[i];
            
            //We cannot start a trip from a station when there is not enough gas to travel to station i+1.
            //So start the circuit from the next station
            if(currTank < 0)
            {
                startIdx = i + 1;
                currTank = 0;
            }
        }
        if(totalTank >= 0)
            return startIdx;
        return -1;
    }
};