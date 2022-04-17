class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<int> mp(26, 0);
        for(int i = 0; i < s.size(); i++)
            mp[s[i] - 'a']++;
        for(int j = 0; j < t.size(); j++)
            mp[t[j] - 'a']--;
        for(int i = 0; i < 26; i++)
            if(mp[i] > 0)
                return false;
        
        return true;
    }
};