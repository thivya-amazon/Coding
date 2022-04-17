class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        vector<int> mp(26, 0);
        vector<int> tempMap(26, 0);
        //Map only the fisrt word
        for(auto c : words[0])
        {
            mp[c - 'a']++;
        }
        
        for(int i = 1; i < words.size(); i++)
        {
            for(auto ch : words[i])
            {
                tempMap[ch - 'a']++;
            }
            //Update actual map comparing it with every other word
            for(int j = 0; j < 26; j++)
            {
                mp[j] = min(mp[j], tempMap[j]);
                tempMap[j] = 0;
            }
        }
        
        for(int i = 0; i < 26; i++)
        {
            if(mp[i] > 0)
            {
                int count = mp[i];
                while(count--)
                {
                    string temp;
                    temp.push_back(i + 'a');
                    result.push_back(temp);
                }  
            }
             
        }
        return result;
    }
};