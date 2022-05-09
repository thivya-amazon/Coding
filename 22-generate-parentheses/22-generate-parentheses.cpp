class Solution {
public:
    vector<string> result;
    void parHelper(int open, int close, string& slate, int n)
    {
        if(open == n && close == n)
        {
            result.push_back(slate);
            return;
        }
        if(open < n)
        {
            slate.push_back('(');
            parHelper(open+1, close, slate, n);
            slate.pop_back();
        }
        if(close < open)
        {
            slate.push_back(')');
            parHelper(open, close+1, slate, n);
            slate.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string slate = "";
        parHelper(0, 0, slate, n);
        return result;
    }
};