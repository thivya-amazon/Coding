class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
    //For each element arr[i], the number contributes to the global answer only if it is the minimum element in a subarray
    //This element is a min element until it finds a previous min element. Calculating the span for the prev min elem provides arr[i] contribution      //to global answer 
        int span = 0;
        vector<int> localAns(arr.size(), 0);
        int globalMin = 0;
        stack<int> mono;
        for(int i = 0; i < arr.size(); i++)
        {
            while(!mono.empty() && arr[mono.top()] >= arr[i])
                mono.pop();
            if(!mono.empty())
            {
                span = i - mono.top();
                //Prev small found and it contributes to the local answer of arr[i]
                localAns[i] = localAns[mono.top()];
            }
            else
                span = i + 1;
            
            mono.push(i);
            localAns[i] += span * arr[i];
            globalMin = (globalMin + localAns[i]) % 1000000007;     
        }
        return globalMin;
    }
};