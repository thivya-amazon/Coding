class Solution {
public:
    int value(char c)
    {
        switch(c)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
    int romanToInt(string s) {
        int first = 0;
        int second = 0;
        int result = 0;
        for(int i = 0; i < s.size(); i++)
        {
            first = value(s[i]);
            if(i+1 < s.size())
            {
                second = value(s[i+1]);
                if(first < second)
                {
                    result += second - first;
                    i++;
                }                    
                else
                    result += first;
            }
            else
                result += first;
        }
        return result;
    }
};