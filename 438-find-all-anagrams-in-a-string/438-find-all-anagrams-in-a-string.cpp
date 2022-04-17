class Solution {
public:

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
            
            //Slide the window
            right++;
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