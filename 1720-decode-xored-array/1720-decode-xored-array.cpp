class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> result;
        result.push_back(first);
        int nextElem = first;
        for(int i = 0; i < encoded.size(); i++)
        {
            nextElem = nextElem ^ encoded[i];
            result.push_back(nextElem);
        }
        return result;
    }
};