class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result = "";
        stack<pair<char, int>> stk;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                result.push_back(s[i]);
                stk.push({s[i], result.size()-1});
            }
            else if(s[i] == ')')
            {
                if(!stk.empty())
                {
                    result.push_back(s[i]);
                    stk.pop();
                }                   
            }
            else
                result.push_back(s[i]);
        }
        while(!stk.empty())
        {
            int length = result.size();
            int index = stk.top().second;
            int nextIdx = index+1;

            if(nextIdx < length)
            {
                string sub = result.substr(nextIdx);
                result.resize(index+length-nextIdx);
                result.replace(index, length-nextIdx, sub);
            }
            else
                result.pop_back();
            stk.pop();
        }
       return result; 
    }
};