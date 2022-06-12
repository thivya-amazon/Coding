class Solution {
public:
    int partition(vector<int>& unique, int start, int end, unordered_map<int, int>& count)
    {
        int pivotIdx = start + rand() % (end - start + 1);
        swap(unique[start], unique[pivotIdx]);
        int pivot = count[unique[start]];
        
        int smaller = start + 1;
        int bigger = end;
       while(smaller <= bigger)
        {
            if(count[unique[smaller]] < pivot)
                smaller++;
           else if(count[unique[bigger]] > pivot)
               bigger--;
           else
           {
               swap(unique[smaller], unique[bigger]);
               smaller++;
               bigger--;
           }
               
        }
        swap(unique[start], unique[bigger]);
        return bigger;
    }
    void quickSelect(vector<int>& unique, unordered_map<int, int>& count, int start, int end, int k)
    {
            int pivotIdx = partition(unique, start, end, count);
        
            if(pivotIdx == k)
               return;
            if(pivotIdx < k)
                quickSelect(unique, count, pivotIdx+1, end, k);
            else
                quickSelect(unique, count, start, pivotIdx-1, k);

    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<int> unique;
        for(int i = 0; i < nums.size(); i++)
            count[nums[i]]++;
        
        //Make an array of unique elements
        for(auto i : count)
            unique.push_back(i.first);
        
        //Perform quick select on the unique array
        int n = unique.size();
        quickSelect(unique, count, 0, n-1, n-k);
        
        vector<int> result;
        // copy(unique.begin() + n - k, unique.end(), result.begin());
        for(int i = n-k; i < n; i++)
            result.push_back(unique[i]);
            
        return result;
    }
};