class Solution {
public:
    struct Log{
        int funcId;
        bool start;
        int timeStamp;
    };
    Log getLog(string s)
    {
        Log item;
        stringstream ss(s);
        string temp;
        
        getline(ss, temp, ':');
        item.funcId = stoi(temp);
        
        getline(ss, temp, ':');
        if(temp == "start")
            item.start = true;
        else
            item.start = false;
        
        getline(ss, temp, ':');
        item.timeStamp = stoi(temp);
        return item;    
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);       
        stack<Log> s;
        
        for(int i = 0; i < logs.size(); i++)
        {
            Log currLog = getLog(logs[i]);
            if(currLog.start)
                s.push(currLog);
            else
            {
                int interval = currLog.timeStamp - s.top().timeStamp + 1;
                result[currLog.funcId] += interval;
                s.pop();
                //If the stack has other entries, the current interval is within a nested interval.
                //So, this value needs to be subtracted for the outer interval
                if(!s.empty())
                {
                    int outerFuncId = s.top().funcId;
                    result[outerFuncId] -= interval;
                }
            }
        }
        return result;
    }
};