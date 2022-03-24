class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        //Mono stack holds the indices
        stack<int> mono;
        for(int i = temperatures.size()-1; i >= 0; i--)
        {
            while(!mono.empty() && temperatures[mono.top()] <= temperatures[i])
                mono.pop();
            if(!mono.empty())
                answer[i] = mono.top() - i;
            mono.push(i);
        }
        return answer;
    }
};