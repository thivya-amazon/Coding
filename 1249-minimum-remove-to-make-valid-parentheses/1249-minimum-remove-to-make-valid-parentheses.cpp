class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result = "";
        stack<int> stk;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                stk.push(i);
            }
            else if(s[i] == ')')
            {
                if(stk.empty())
                   s[i] = '$';
                else
                    stk.pop();
            }
        }
        while(!stk.empty())
        {
            s[stk.top()] = '$';
            stk.pop();
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '$')
                result.push_back(s[i]);
        }
            
       return result; 
    }
};