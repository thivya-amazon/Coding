class Solution {
public:
    int calculate(string s) {
        int length = s.size();
        int number = 0;
        char operation = '+';
        stack<int> stk;
        //Step 1: Extract the number to operate on or if it is an expression, recursively evaluate it and find the number
        for(int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i]))
            {
                number = number*10 + (s[i] - '0');
            }
            //Find the outermost expression within parantheses 
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
                int length = j-i-1;
                number = calculate(s.substr(i+1, length));
                //Reset i back to the last character in order to continue the loop
                i = j-1;
            }
            
            //Step 2: Find the operator and perform necessary action
            if(!isdigit(s[i]) && !iswspace(s[i]) || i == length-1)
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
                operation = s[i];
                number = 0;
            }
        }
        
        int result = 0;
        while(!stk.empty())
        {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};