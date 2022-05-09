class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> mono;
        vector<int> result(n, 0);
        int span = 0;
        for(int i = n-1; i >= 0; i--)
        {
            while(!mono.empty() && temperatures[i] >= temperatures[mono.top()])
                mono.pop();
            if(!mono.empty())
            {
                span = mono.top() - i;
                result[i] = span;
            }
            mono.push(i);
        }
        return result;
    }
};