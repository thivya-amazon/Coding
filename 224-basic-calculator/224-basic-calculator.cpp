class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        stack<pair<int, int>> stk;
        int sum = 0;
        int sign = 1;
        
        for(int i = 0; i < s.size(); i++)
        {
            //Char is a digit
            if(isdigit(s[i]))
            {
                //Form the complete num
                int num = 0;
                while(isdigit(s[i]) && i < len)
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                //To get the index back to the last numeric digit
                i--;
                sum += (num * sign);
                sign = 1;                   
            }
            else if(s[i] == '-')
            {
                sign = -1;
            }
            else if(s[i] == '(')
            {
                //Push the sum and sign upto this point into a stack and get ready to process the inner expression
                stk.push({sum,sign});
                sum = 0;
                sign = 1;
            }
            else if(s[i] == ')')
            {
                //Pop the stack and populate sum and sign values since the inner expression is evaluated
                sum = stk.top().first + (stk.top().second*sum);
                stk.pop();
            }
        }
        return sum;
    }
};