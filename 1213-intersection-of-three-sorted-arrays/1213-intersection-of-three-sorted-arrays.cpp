class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> sortedTwo;
        vector<int> result;
        int index1 = 0;
        int index2 = 0;
        int index3 = 0;
        while(index1 < arr1.size() && index2 < arr2.size())
        {
            if(arr1[index1] == arr2[index2])
            {
                sortedTwo.push_back(arr1[index1]);
                index1++;
                index2++;
            }
               
            else if(arr1[index1] > arr2[index2])
                index2++;
            else
                index1++;
        }
        index1 = 0;
        while(index3 < arr3.size() && index1 < sortedTwo.size())
        {
            if(arr3[index3] == sortedTwo[index1])
            {
                result.push_back(sortedTwo[index1]);
                index3++;
                index1++;
            }
            else if(arr3[index3] > sortedTwo[index1])
                index1++;
            else
                index3++;
        }
        return result;
    }
};