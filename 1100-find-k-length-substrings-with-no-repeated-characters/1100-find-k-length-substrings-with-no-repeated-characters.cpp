class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int count = 0;
        
        if(k > s.size())
            return 0;
        unordered_map<char, int> chars(k);
        for(int i = 0; i < k; i++)
        {
            // if(chars.count(s[i]))
            // {
            //     chars[s[i]]++;
            // }             
            // else
            //     chars[s[i]] = 1;
             chars[s[i]]++;
        }
        if(chars.size() == k)
            count++;
        for(int i = k; i < s.size(); i++)
        {            
            //Remove the leftmost element in the window
            chars[s[i-k]]--;
            if(chars[s[i-k]] == 0)
                chars.erase(s[i-k]);

            // if(chars.count(s[i]))
            // {
            //     chars[s[i]]++;
            // }             
            // else
            //     chars[s[i]] = 1;
             chars[s[i]]++;
            
            if(chars.size() == k)
                count++;

        }
        return count;
    }
};