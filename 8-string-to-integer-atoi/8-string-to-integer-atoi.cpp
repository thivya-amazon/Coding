class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        long long tempResult = 0;
        int sign = 1;
        
        if(s.size() < 1)
            return 0;
        //Remove leading whitespaces
        int i = 0;
        while(i < s.size())
        {
            if(isspace(s[i]))
                s.erase(s.begin());
            else
                break;
        }
        //Collect the sign
            if(s[0] == '+')
            {
                sign = 1;
                s.erase(s.begin());
            }
            else if(s[0] == '-')
            {
                sign = -1;
                s.erase(s.begin());
            }               

        for(int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i]))
            {
                int digit = s[i] - '0';
                if((tempResult > INT_MAX / 10) || (tempResult == INT_MAX/10 && digit > INT_MAX % 10 ))
                {
                    if(sign == 1)
                        return INT_MAX;
                    else
                        return INT_MIN;
                }

                tempResult = tempResult*10 + digit;
            }
            else
                break;
        }

        result = sign * tempResult;
        
        return result;
    }
};