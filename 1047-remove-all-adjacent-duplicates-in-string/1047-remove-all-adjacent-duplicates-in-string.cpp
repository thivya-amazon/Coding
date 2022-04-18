class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        if(s.size() <= 1)
            return s;
//         for(int i = 0; i < s.size(); i++)
//         {
//             int index = i+1;
//             while(index < s.size() && s[i] == s[index])
//                 index++;
//             if(index > i+1)
//             {
//                 if((index - i) % 2 == 0)
//                     s.erase(s.begin()+i, s.begin()+index);
//                 else
//                     s.erase(s.begin()+i, s.begin()+index-1);
//                 i = -1;
//             }
                           
//         }
//         return s;
        stack<char> stk;
        for(int i = 0; i < s.size(); i++)
        {
            if(!stk.empty() && s[i] == stk.top())
                stk.pop();
            else
                stk.push(s[i]);
        }
        while(!stk.empty())
        {
           result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};