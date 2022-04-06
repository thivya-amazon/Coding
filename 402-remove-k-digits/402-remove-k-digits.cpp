class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == 0)
            return num;
        stack<char> mono;
        string result;
        for(int i = 0; i < num.size(); i++)
        {
            while(k > 0 && !mono.empty() && mono.top() > num[i])
            {
                mono.pop();
                k--;
            }
            mono.push(num[i]);
            
            if(mono.size() == 1 && mono.top() == '0')
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
            result.push_back(mono.top());
            mono.pop();
        }
        reverse(result.begin(), result.end());
        if(result.size() == 0)
            return "0";
        return result;
    }
};