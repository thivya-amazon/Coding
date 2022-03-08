class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else
            {
                if(stk.empty())
                    return false;
                char match = stk.top();
                stk.pop();
                switch(s[i])
                {
                    case ')':
                    if(match != '(')
                        return false;
                    break;
                        
                    case ']':
                    if(match != '[')
                        return false;
                    break;
                        
                    case '}':
                    if(match != '{')
                        return false;
                    break;
                        
                }
            }
        }
        if(!stk.empty())
            return false;
        
        return true;
    }
};