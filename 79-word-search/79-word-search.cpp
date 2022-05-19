class Solution {
public:
    bool dfs(int index, vector<vector<char>>& board, string& word, int row, int col)
    {
        int ROWS = board.size();
        int COLS = board[0].size();
        //Step 1 : Check if all the indices of the word are consumed
        if(index == word.size())
            return true;
        //Step 2: Check for boundary conditions and match
        if(row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != word[index])
            return false;
        //Step 3: Condtions met - Launch DFS in all 4 directions
        board[row][col] = '0';      //Mark as visited
        bool status = true;
        status = dfs(index + 1, board, word, row + 1, col) ||
                dfs(index + 1, board, word, row - 1, col) ||
                dfs(index + 1, board, word, row, col + 1) ||
                dfs(index + 1, board, word, row, col - 1);
        
        //Step 4: backtrack to try a new path
        board[row][col] = word[index];
        return status;            
    } 
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();
        
        for(int i = 0; i < ROWS; i++)
            for(int j = 0; j < COLS; j++)
            {
                if(board[i][j] == word[0] && dfs(0, board, word, i, j))
                    return true;
            }
        return false;
    }
};