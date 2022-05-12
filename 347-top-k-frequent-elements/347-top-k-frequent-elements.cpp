class Solution {
public:
    struct compare{
        bool operator()(const pair<int,int> num1, const pair<int,int> num2)
        {
            return num1.second < num2.second;
        }
            
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
            umap[nums[i]]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq(umap.begin(), umap.end());
        
        for(int i = 0; i < k; i++)
        {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};