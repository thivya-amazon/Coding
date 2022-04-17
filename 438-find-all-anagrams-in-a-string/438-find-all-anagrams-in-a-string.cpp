class Solution {
public:
    bool isAnagram(string& s, string& p, int index)
    {
        unordered_map<char, int>mp;
        for(int i = 0; i < p.size(); i++)
        {
            mp[p[i]]++;
        }
        string test = s.substr(index, p.size());
        for(int i = 0; i < test.size(); i++)
        {
            mp[test[i]]--;
        }
        for(int i = 0; i < p.size(); i++)
        {
            if(mp[p[i]] > 0)
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> shash(26, 0);
        vector<int> phash(26, 0);
        int window = p.size();
        int left = 0;
        int right = 0;
        
        if(p.size() > s.size())
            return result;
        while(right < window)
        {
            phash[p[right] - 'a']++;
            shash[s[right] - 'a']++;
            right++;
        }
        //Reset right back to the next element past the window
        right--;
        while(right < s.size())
        {
            if(phash == shash)
                result.push_back(left);
            right++;
            //Slide the window
            if(right != s.size())
            {
                shash[s[right] - 'a']++;
                shash[s[left] - 'a']--;
            }
            left++;
        }
        return result;
    }
};