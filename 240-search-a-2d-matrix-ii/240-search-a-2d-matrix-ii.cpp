class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int minRow = 0;
        int maxCol = cols-1;
        
        while(minRow < rows && maxCol >= 0)
        {
            if(matrix[minRow][maxCol] == target)
                return true;
            //Eliminate maxCol from the search
            else if(target < matrix[minRow][maxCol])
                maxCol--;
            //Eliminate minRow from the search
            else
                minRow++;
        }
        return false;
    }
};