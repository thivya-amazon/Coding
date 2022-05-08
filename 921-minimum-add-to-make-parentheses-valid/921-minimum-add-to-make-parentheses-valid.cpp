class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size() == 0)
            return 0;
        stack<char> stk;
        int count = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                stk.push(s[i]);
            else if(s[i] == ')')
            {
                if(stk.empty())
                    count++;
                else
                    stk.pop();
            }
        }
        while(!stk.empty())
        {
            count++;
            stk.pop();
        }
        // for(int i = 0; i < s.size(); i++)
        // {
        //     if(s[i] == '$')
        //         count++;
        // }
        return count;
    }
};