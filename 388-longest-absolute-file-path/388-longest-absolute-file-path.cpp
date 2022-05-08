class Solution {
public:

    int lengthLongestPath(string input) {
        string item;
        stringstream ss(input);
        size_t found;
        int maxLength = 0;
        vector<int> pathLength(input.size());
        while(!ss.eof())
        {
            getline(ss, item, '\n');
            int numTabs = 0;
            while(item[numTabs] == '\t')
                numTabs++;
            //root level
            if(numTabs == 0)
                pathLength[numTabs] = item.size();
            else
            {
                pathLength[numTabs] = pathLength[numTabs-1] + 1 + item.substr(numTabs).size();
            }
            if(item.find('.') != string::npos)
                maxLength = max(maxLength, pathLength[numTabs]);
        }
       return maxLength; 
        
    }
};