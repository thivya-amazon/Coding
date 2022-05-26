class NumMatrix {
public:
    vector<vector<int>> prefixSum;
    int ROWS;
    int COLS;
    NumMatrix(vector<vector<int>>& matrix) {
        ROWS = matrix.size();
        COLS = matrix[0].size();
        prefixSum.resize(ROWS, vector<int>(COLS, 0));
        populatePrefixSums(matrix);
    }
    
    void populatePrefixSums(vector<vector<int>>& matrix)
    {
        //Initialization of first row and first col
        prefixSum[0][0] = matrix[0][0];
        for(int i = 1; i < ROWS; i++)
            prefixSum[i][0] = prefixSum[i-1][0] + matrix[i][0];
        for(int i = 1; i < COLS; i++)
            prefixSum[0][i] = prefixSum[0][i-1] + matrix[0][i];
        
        for(int i = 1; i < ROWS; i++)
            for(int j = 1; j < COLS; j++)
                prefixSum[i][j] = matrix[i][j] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];       
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0)
            return prefixSum[row2][col2];
        if(row1 == 0)
            return prefixSum[row2][col2] - prefixSum[row2][col1-1];
        if(col1 == 0)
            return prefixSum[row2][col2] - prefixSum[row1-1][col2];
        return prefixSum[row2][col2] - prefixSum[row2][col1-1] - prefixSum[row1-1][col2] + prefixSum[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */