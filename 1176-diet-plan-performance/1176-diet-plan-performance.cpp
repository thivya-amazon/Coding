class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int points = 0;
        int calConsumed = 0;
        for(int i = 0; i < k; i++)
            calConsumed += calories[i];
        if(calConsumed > upper)
            points++;
        else if(calConsumed < lower)
            points--;
        for(int i = k; i < calories.size(); i++)
        {
            calConsumed += calories[i] - calories[i-k];
            if(calConsumed > upper)
                points++;
            else if(calConsumed < lower)
                points--;            
        }
        return points;
    }
};