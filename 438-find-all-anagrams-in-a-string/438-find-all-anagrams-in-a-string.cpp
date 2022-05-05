class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(p.size() > s.size())
            return result;
        vector<int> phash(26, 0);
        vector<int> shash(26, 0);
        
        int k  = p.size();
        for(int i = 0; i < k; i++)
        {
            phash[p[i] - 'a']++;
            shash[s[i] - 'a']++;
        }
        if(phash == shash)
            result.push_back(0);
        for(int i = k; i < s.size(); i++)
        {
            shash[s[i] - 'a']++;
            shash[s[i-k] - 'a']--;
            if(phash == shash)
                result.push_back(i-k+1);
        }
        return result;
    }
};