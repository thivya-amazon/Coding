class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        if(k == 0)
            return num;
        stack<int> mono;
        //Find the previous min element for every num[i]
        for(int i = 0; i < num.size(); i++)
        {
            while(!mono.empty() && mono.top() > (num[i] - '0') && k > 0)
            {
                mono.pop();
                k--;
            }
            mono.push(num[i] - '0');
            if(mono.size() == 1 && mono.top() == 0)
                mono.pop();
        }
        
        //For strictly increasing strings
        while(k && !mono.empty())
        {
            mono.pop();
            k--;
        }
        
        while(!mono.empty())
        {
            result.push_back(mono.top() + '0');
            mono.pop();
        }
        reverse(result.begin(), result.end());
        if(result.size() == 0)
            return "0";
        return result;
    }
};