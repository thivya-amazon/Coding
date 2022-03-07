class Solution {
public:
    int countOnes(int num)
    {
        int count = 0;
        while(num)
        {
            num = num & (num-1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i = 0; i <=n; i++)
        {
            result.push_back(countOnes(i));
        }
        return result;
    }
};