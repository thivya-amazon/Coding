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
        int direction = 1;
        while(result.size() < ROWS * COLS)
        {
            //1. Traverse left to right & move the top boundary after the row is traversed
            if(direction == 1)
            {
                for(int i = left; i <= right; i++)
                    result.push_back(matrix[top][i]);
                top++;
                direction = 2;
            }

             //2. Traverse from top to bottom and move the right boundary after the column is traversed
            else if(direction == 2)
            {
                for(int i = top; i <= bottom; i++)
                    result.push_back(matrix[i][right]);
                right--;
                direction = 3;
            }
            
            //3. Traverse from right to left and move the bottom boundary after the row is traversed
            else if(direction == 3)
            {
                for(int i = right; i >= left; i--)
                    result.push_back(matrix[bottom][i]);
                bottom--;
                direction = 4;
            }  
            
            //4. Traverse from bottom to top and move the left boundary after the column is traversed
            else if(direction == 4)
            {
                for(int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
                direction = 1;
            }
                     
        }
        return result;
    }
};