class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        int top = 0;
        int bottom = ROWS - 1;
        int left = 0;
        int right = COLS - 1;
        while(result.size() < ROWS * COLS)
        {
            //1. Traverse left to right & move the top boundary after the row is traversed
            for(int i = left; i <= right; i++)
                result.push_back(matrix[top][i]);
            top++;
            
            //2. Traverse from top to bottom and move the right boundary after the column is traversed
            for(int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;
            
            if(left > right || top > bottom)
                break; 
            
            //3. Traverse from right to left and move the bottom boundary after the row is traversed
            for(int i = right; i >= left; i--)
                result.push_back(matrix[bottom][i]);
            bottom--;
        
            
            //4. Traverse from bottom to top and move the left boundary after the column is traversed
            for(int i = bottom; i >= top; i--)
                result.push_back(matrix[i][left]);
            left++;           
        }
        return result;
    }
};