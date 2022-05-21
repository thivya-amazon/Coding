class Solution {
public:
    int calculate(string s) {
        int result = 0;
        if(s.size() == 0)
            return result;
        int number = 0;
        char operation = '+';
        stack<int> stk;
        for(int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i]))
                number = number*10 + (s[i] - '0');
            else if(s[i] == '(')
            {
                int j = i+1;
                int braces = 1;
                while(braces > 0)
                {
                    if(s[j] == '(')
                        braces++;
                    else if(s[j] == ')')
                        braces--; 
                    j++;
                }
                int len = j-i-1;
                number = calculate(s.substr(i+1, len));
                i = j-1;
            }

            if((!isdigit(s[i]) && !isspace(s[i])) || i == s.size()-1)
                {
                    switch(operation)
                    {
                        case '+':
                           stk.push(number);
                           break;
                            
                        case '-':
                            stk.push(-number);
                            break;
                            
                        case '*':
                            if(!stk.empty())
                            {
                                int prev = stk.top();
                                stk.pop();
                                stk.push(prev*number);
                            }
                            break;
                        case '/':
                            if(!stk.empty())
                            {
                                int prev = stk.top();
                                stk.pop();
                                stk.push(prev/number);
                            }
                            break;
                    }
                    operation = s[i];
                    number = 0;
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