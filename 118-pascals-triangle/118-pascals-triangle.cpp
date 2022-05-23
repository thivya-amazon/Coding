class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> table;
        for(int i = 0; i < numRows; i++)
        {
            vector<int> temp(i + 1);
            table.push_back(temp);
            table[i][0] = 1;
            table[i][i] = 1;
        }
        
        for(int i = 1; i < numRows; i++)
            for(int j = 1; j < i; j++)
            {
                table[i][j] = table[i-1][j-1] + table[i-1][j];
            }
        
        return table;
    }
};