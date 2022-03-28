class Solution {
public:
    int calculate(string s) {
        int result = 0;
        stack<int> stk;
        char operation = '+';
        int num = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i]))
            {
                num = num*10 + (s[i] - '0');                
            }
            if(!isdigit(s[i]) && !iswspace(s[i]) || i == s.size()-1)
            {
                if(operation == '+')
                    stk.push(num);
                else if(operation == '-')
                    stk.push(-num);
                else if(operation == '*')
                {
                    int prevNum = stk.top();
                    stk.pop();
                    stk.push(prevNum * num);
                }
                else if(operation == '/')
                {
                    int prevNum = stk.top();
                    stk.pop();
                    stk.push(prevNum / num);
                }
                operation = s[i];
                num  = 0;                   
            }
        }
        while(!stk.empty())
        {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};