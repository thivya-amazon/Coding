class Solution {
public:
    bool trusts(int person1, int person2, vector<vector<int>>& adjList)
    {
        vector<int> :: iterator it;
        for(it = adjList[person1].begin(); it != adjList[person1].end(); it++)
        {
            if(*it == person2)
                return true;
        }
        return false;
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        //Build the adj list from the edge list
        vector<vector<int>> adjList(n+1);
        for(auto e : trust)
        {
            adjList[e[0]].push_back(e[1]);
        }
        //Assume judge = 1 and start finding a survivor who would not trust anyone else
        int survivor = 1;
        for(int i = 1; i <= n; i++)
        {
            if(!trusts(i, survivor, adjList))
                survivor = i;
        }
        bool flag ;
        //At this point, validate if survivor is the judge
        for(int i = 1; i <= n; i++)
        {
            vector<int> :: iterator it;
            //check if all others trust the survivor
            if(i != survivor)
            {
                if(trusts(survivor, i, adjList) || !trusts(i, survivor, adjList))
                    return -1;
            }
        }

        return survivor;
    }
};