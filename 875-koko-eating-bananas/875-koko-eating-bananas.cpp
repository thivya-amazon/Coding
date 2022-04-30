class Solution {
public:
   //Zones :  | k too low, hours taken > H | k too fast, hours taken <= H |
    int minEatingSpeed(vector<int>& piles, int h) {
        //Find the max number of bananas in a pile
        //This will be the upper limit on Koko's eating speed
        int maxBananas = INT_MIN;
        for(int i = 0; i < piles.size(); i++)
            maxBananas = max(maxBananas, piles[i]);
        
        int startK = 1;
        int endK = maxBananas;
        
        while(startK <= endK)
        {
            //We need to figure out the hours taken to eat all the piles from the chosen speed
            int hoursTaken = 0;
            int midK = startK + (endK - startK)/2;
            for(int i = 0; i < piles.size(); i++)
                hoursTaken += ceil(1.0 * piles[i]/midK);
            if(hoursTaken > h)
                startK = midK + 1;
            else
                endK = midK - 1;            
        }
        return startK;
    }
};