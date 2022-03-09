class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        vector<string> res(numRows);
        string result = "";
        int strIndex = 0;
        int zigzagIdx = strIndex;
        while(strIndex < s.size())
        {
            if(zigzagIdx >= 0 && zigzagIdx < numRows)
            {
                res[zigzagIdx].push_back(s[strIndex++]);
                zigzagIdx++;
            }
            else
            {
                zigzagIdx = numRows-2;
                while(zigzagIdx >= 0 && strIndex < s.size())
                {
                    res[zigzagIdx--].push_back(s[strIndex++]);
                }
                zigzagIdx = 1;
            }
        }
        for(int i = 0; i < numRows; i++)
        {
            if(res[i].size() != 0)
            {
                cout << res[i] << endl;
                result.append(res[i]);
            }
        }
        return result;
        
    }
};