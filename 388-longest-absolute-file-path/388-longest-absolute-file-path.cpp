class Solution {
public:
    int lengthLongestPath(string input) {
        string item;
        stringstream ss(input);
        int maxLength = 0;
        unordered_map<int,int> levelLength;
        while(getline(ss, item, '\n'))
        {
            int numTabs = 0;
            while(item[numTabs] == '\t')
                numTabs++;
            if(numTabs == 0)
                levelLength[numTabs] = item.size();
            else
            {
                levelLength[numTabs] = levelLength[numTabs-1] + 1 + item.substr(numTabs).size();
            }
            if(item.find('.') != string::npos)
                maxLength = max(maxLength, levelLength[numTabs]);
        }
        return maxLength;
    }
};