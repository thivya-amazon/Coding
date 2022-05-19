class Solution {
public:
    int getNumLiveNeighbors(vector<vector<int>>& board, int row, int col)
    {
        int ROWS = board.size();
        int COLS = board[0].size();
        int count = 0;
        vector<int> x_dir = {0, 0, 1, -1, -1, -1, 1, 1};
        vector<int> y_dir = {1, -1, 0, 0, -1, 1, -1, 1};
        for(int i = 0; i < 8; i++)
        {
            int n_x = row + x_dir[i];
            int n_y = col + y_dir[i];
            if(n_x >= 0 && n_x < ROWS && n_y >= 0 && n_y < COLS)
                if(board[n_x][n_y] == 1)
                    count++;
        }    
        return count;                  
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy = board;
       int ROWS = board.size();
        int COLS = board[0].size();
        for(int i = 0 ; i < ROWS; i++)
            for(int j = 0; j < COLS; j++)
            {
                int neighbors = getNumLiveNeighbors(copy, i, j);
                if(board[i][j] == 1)
                {
                    if(neighbors < 2 || neighbors > 3) 
                        board[i][j] = 0;
                }
                else
                {
                    if(neighbors == 3)
                        board[i][j] = 1;
                }
            }
    }
};