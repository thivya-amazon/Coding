class Solution {
public:
    int calculate(string s) {
        int number = 0;
        char operation = '+';
        stack<int> stk;
        
        for(int i = 0; i < s.size(); i++)
        {
            //Find the number to operate on
            if(isdigit(s[i]))
                number = number * 10 + (s[i] - '0');
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
                //length of the outermost expression within parantheses
                int length = j-i-1;
                number = calculate(s.substr(i+1, length));
                //Reset i back to the last character
                i = j-1;
            }
            
            //Find the operator and operate on the number
            if(!isdigit(s[i]) && !iswspace(s[i]) || i == s.size()-1)
            {
                if(operation == '+')
                    stk.push(number);
                else if(operation == '-')
                    stk.push(-number);
                else if(operation == '*')
                {
                    int prevNum = stk.top();
                    stk.pop();
                    stk.push(prevNum * number);
                }
                else if(operation == '/')
                {
                    int prevNum = stk.top();
                    stk.pop();
                    stk.push(prevNum / number);
                }
                //Update the operation and reset the number to get the next number
                operation = s[i];
                number = 0;
            }
        }
        
        //Stack has all the number with appropriate signs. Just adding all of them gives the result
        int result = 0;
        while(!stk.empty())
        {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};