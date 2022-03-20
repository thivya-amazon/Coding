class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int maxCol = cols-1;
        int minRow = 0;
        
        //Check for boundary conditions
        while(minRow < rows && maxCol >= 0)
        {
            if(matrix[minRow][maxCol] == target)
                return true;
            else if(target < matrix[minRow][maxCol])
                maxCol--;
            else
                minRow++;
        }
        return false;
            
    }
};