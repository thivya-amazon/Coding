class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        //Use BFS with every index in s as a node
        int n = s.size();
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        while(!q.empty())
        {
            int start = q.front();
            q.pop();
            if(visited[start])
                continue;
            for(int end = start+1; end <= n; end++)
            {
                string sub = s.substr(start, end-start);
                if(dict.count(sub))
                {
                    q.push(end);
                    //The entire string s has been parsed
                    if(end == n)
                        return true;
                }
            }
            visited[start] = true;
        }
        return false;
    }
};