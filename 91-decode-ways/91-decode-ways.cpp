class Solution {
public:
    map<int, int> memo;
    int decodeHelper(int sub_idx, string s)
    {        
        if(memo.find(sub_idx) != memo.end())
            return memo[sub_idx];
        
        if(sub_idx == s.size())
            return 1;
        
        if(s[sub_idx] == '0')
            return 0;
        if(sub_idx == s.size()-1)
            return 1;
        
        //consider 1 digit
        int count = decodeHelper(sub_idx+1, s);
        if(stoi(s.substr(sub_idx, 2)) <= 26)
            count += decodeHelper(sub_idx+2, s);
        
        memo[sub_idx] = count;
        return count;
    }
    
    int numDecodings(string s) {
        return decodeHelper(0, s);
    }
};
    
