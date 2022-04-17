class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<int> count(26, 0);
        unordered_map<string, vector<string>> umap;
        for(auto s : strs)
        {
            for(int i = 0; i < s.size(); i++)
                count[s[i] - 'a']++;
            string key = "";
            for(int j = 0; j < 26; j++)
            {
                //Without having a delimiter multi-digit count values cannot be differentiated
                key.push_back('#');
                key.append(to_string(count[j]));
            }
            umap[key].push_back(s);
            //Reset the count vector
            for(int i = 0; i < s.size(); i++)
                count[s[i] - 'a']--;
        }
        for(auto i = umap.begin(); i != umap.end(); i++)
        {
            result.push_back(i->second);
        }
        return result;
    }
};