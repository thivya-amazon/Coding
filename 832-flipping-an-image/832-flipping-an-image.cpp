class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int ROW = image.size();
        int COL = image[0].size();
        
        //Reverse each row
        for(int i = 0; i < ROW; i++)
        {
            reverse(image[i].begin(), image[i].end());
        }
        
        //Flip the bits
        for(int i = 0; i < ROW; i++)
            for(int j = 0; j < COL; j++)
            {
                image[i][j] = !image[i][j];
            }
        return image;
    }
};