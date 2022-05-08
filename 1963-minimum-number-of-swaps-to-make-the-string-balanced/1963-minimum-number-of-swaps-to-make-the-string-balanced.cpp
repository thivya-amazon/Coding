class Solution {
public:
    int minSwaps(string s) {
        stack <int> stk;
        int numSwaps = 0;
        if(s.size() == 0)
            return 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '[')
                stk.push(i);
            else
            {
                if(!stk.empty())
                    stk.pop();
            }
        }
        int sz = stk.size();
        if(sz % 2 == 0)
            return sz/2;
        return (sz+1)/2;
        
    }
};