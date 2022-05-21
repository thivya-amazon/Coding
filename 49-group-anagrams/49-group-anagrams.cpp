class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> umap;
        vector<int> charCount(26, 0);
        for(auto s  : strs)
        {
            //1. Count the chars in every string
            for(int i = 0; i < s.size(); i++)
                charCount[s[i] - 'a']++;
            
            //2. Form a key of count of chars with delimiters 
            string key = "";
            for(int j = 0; j < 26; j++)
            {
                key.push_back('#');
                key.push_back(charCount[j]);
            }
            
            //3. Insert key into umap with value as a vector of strings corresponding to the key generated ins tep 2
            umap[key].push_back(s);
            
            //4.Reset count vector for the next string
            for(int i = 0; i < s.size(); i++)
                charCount[s[i] - 'a']--;
        }
        
        for(auto i = umap.begin(); i != umap.end(); i++)
        {
            result.push_back(i->second);
        }
        return result;
    }
};