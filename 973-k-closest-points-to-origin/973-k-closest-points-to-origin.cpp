class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //Maxheap to store the k closest points
        priority_queue<pair<int,int>> maxHeap;
        for(int i = 0; i < points.size(); i++)
        {
            //Push index and Euclidean distance(squared) into max heap
            pair<int, int> heapEntry = {(points[i][0]*points[i][0] + points[i][1]*points[i][1]), i};
            maxHeap.push(heapEntry);
            
            if(maxHeap.size() > k)
                maxHeap.pop();
        }
        
        vector<vector<int>> result;
        while(!maxHeap.empty())
        {
            int index = maxHeap.top().second;
            result.push_back(points[index]);
            maxHeap.pop();
        }
        return result;
    }
};