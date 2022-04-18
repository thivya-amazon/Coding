class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> stk;
        int j = 0;
        for(int i = 0; i < s.size(); i++, j++)
        {
            s[j] = s[i];
            if(j == 0 || s[j] != s[j-1])
                stk.push(1);
            else
            {
                int count = ++stk.top();
                if(k == count)
                {
                    stk.pop();
                    j = j-k;
                }                    
            }
        }
        return s.substr(0, j);
    }
};