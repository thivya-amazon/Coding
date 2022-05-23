class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<string> uset;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    string row = "r-" + to_string(i) + to_string(board[i][j]);
                    string col = "c-" + to_string(j) + to_string(board[i][j]);
                    int x = i/3;
                    int y = j/3;
                    string box = "b-" + to_string(x) + "-" + to_string(y) + to_string(board[i][j]);
                    if(uset.count(row) || uset.count(col) || uset.count(box))
                        return false;
                    uset.insert(row);
                    uset.insert(col);
                    uset.insert(box);
                }
            }
        return true;
    }
};