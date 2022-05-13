class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        unordered_map<char, int> s1chars(26);
        unordered_map<char, int> s2chars(26);
        //Push all characters in s1 into its hash map
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1chars.count(s1[i]))
                s1chars[s1[i]]++;
            else
                s1chars[s1[i]] = 1;
        }
         //Push the window size characters in s2 into its hash map
        for(int i = 0; i < s1.size(); i++)
        {
            if(s2chars.count(s2[i]))
                s2chars[s2[i]]++;
            else
                s2chars[s2[i]] = 1;
        }
        if(s1chars == s2chars)
            return true;  
        int k = s1.size();
        for(int i = k; i < s2.size(); i++)
        {
            s2chars[s2[i-k]]--;
            if(s2chars[s2[i-k]] == 0)
                s2chars.erase(s2[i-k]);            

            s2chars[s2[i]]++;
             
            if(s1chars == s2chars)
                return true;            
        }
        return false;
    }
};