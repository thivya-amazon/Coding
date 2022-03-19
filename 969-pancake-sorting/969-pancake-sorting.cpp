class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {        
        /*Pancake sort
        Decrease & Conquer
        for each manager i from n-1 to 0
            1. Find the largest pancake until index i  
            2. Flip the largest pancake to be at the top of the stack
            3. Flip again to bring the largest pancake to the bottom
        When each manager does this, the stack will be sorted    
        */
        vector<int> result;
         int n = arr.size();
        int i = 0;
        int j = 0;
        for(i = n-1; i > 0; i--)
        {
            if(arr[i] != i+1)
            {
                for(j = i-1; j >= 0; j--)
                {
                    if(arr[j] == i+1)
                        break;
                }
                //Take the largest pancake to the top of the stack
                reverse(arr.begin(), arr.begin()+j+1);
                //Capture the number of pancakes flipped in result
                result.push_back(j+1);
                //Take the largest pancake to the bottom of the stack
                reverse(arr.begin(), arr.begin()+i+1);
                result.push_back(i+1);
            }

        }
        return result;
    }
};