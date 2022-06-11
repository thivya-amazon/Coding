class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        vector<vector<int>> rotMatrix(COLS, vector<int>(ROWS, 0));
        for(int row = 0; row < ROWS; row++)
            for(int col = row; col < COLS; col++)
            {
                swap(matrix[row][col], matrix[col][row]);
            }
        
        for(int row = 0; row < ROWS; row++)
        {
            int left = 0;
            int right = COLS-1;
            while(left < right)
            {
                swap(matrix[row][left], matrix[row][right]);
                left++;
                right--;
            }
        }

    }
};