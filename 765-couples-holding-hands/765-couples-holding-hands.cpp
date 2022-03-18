class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size()/2;
        int numSwaps = 0;
        //populate a hash map to retrieve seat index for every person in O(1) time
        unordered_map<int,int> umap;
        for(int i = 0; i < 2*n; i++)
        {
            umap[row[i]] = i;
        }
        
        //Consider the 2n seats to be divided as n sofas - 1 for each couple
        for(int i = 0; i < n; i++)
        {
            int leftPerson = row[2*i];
            int rightPerson = row[2*i + 1];
            int expectedRight;
            
            //Since a couple have consecutive indices and for min swaps we need the array to start from leftPerson and go on
            if(leftPerson % 2)
                expectedRight = leftPerson - 1;
            else
                expectedRight = leftPerson + 1;
            //When the rightPerson is not the right pair
            while(rightPerson != expectedRight)
            {
                //Find the index of expected right from the hashmap
                int expectedRightIndex = umap[expectedRight];
                
                //Swap rightPerson with expectedRight and increment count
                swap(row[2*i + 1], row[expectedRightIndex]);
                numSwaps++;
                //Update the hashmap with the new positions
                umap[row[2*i+1]] = 2*i + 1;
                umap[row[expectedRightIndex]] = expectedRightIndex;
                rightPerson = row[2*i +  1];
            }
        }
        return numSwaps;
    }
};