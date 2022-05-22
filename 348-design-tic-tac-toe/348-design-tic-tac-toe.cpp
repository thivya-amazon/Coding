class TicTacToe {
public:
    vector<vector<int>> board;
    int num;
    TicTacToe(int n) {
        board.resize(n);
        for(int i = 0; i < n; i++)
            board[i].resize(n, 0);
        num = n;
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;
        if(checkRow(row, col, player) ||
           checkCol(row, col, player) ||
         ((row == col) && checkDiagonal(player)) ||
           ((col == num - row - 1) && checkAntiDiagonal(player)))
           return player;
        
        return 0;
    }
    
    private:
    bool checkRow(int row, int col, int player)
    {
        for(int c = 0; c < num; c++)
            if(board[row][c] != player)
                return false;
        return true;
    }
    
    bool checkCol(int row, int col, int player)
    {
        for(int r = 0; r < num; r++)
            if(board[r][col] != player)
                return false;
        return true;
        
    }
    
    bool checkDiagonal(int player)
    {
        for(int r = 0; r < num; r++)
            if(board[r][r] != player)
                return false;
        return true;
    }
    
    bool checkAntiDiagonal(int player)
    {
        for(int r = 0; r < num; r++)
            if(board[r][num-r-1] != player)
                return false;
        return true;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */