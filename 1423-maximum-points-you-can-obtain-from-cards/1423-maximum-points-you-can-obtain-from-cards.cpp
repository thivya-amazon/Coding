class Solution {
public:
    //Minimize the score for (n-k) window. So, that the remaining elements' score is maximized
    int maxScore(vector<int>& cardPoints, int k) {
        int windowSize = cardPoints.size() - k;
        int windowSum = 0;
        int minScore = INT_MAX;
        for(int i = 0; i < windowSize; i++)
        {
            windowSum += cardPoints[i];
        }
        minScore = min(minScore, windowSum);
        for(int i = windowSize; i < cardPoints.size(); i++)
        {
            windowSum += cardPoints[i] - cardPoints[i-windowSize];
            minScore = min(minScore, windowSum);
        }
        
        int totalScore = 0;
        for(auto i : cardPoints)
            totalScore += i;
        
        return totalScore - minScore;
        
    }
};