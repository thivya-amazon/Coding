class Solution {
public:
    string simplifyPath(string path) {
        string name = "";
        stack<string> s;
        
        for(int i = 0; i < path.size(); i++)
        {
            string name = "";
            if(path[i] != '/')
            {
                while(i < path.size() && path[i] != '/')
                {
                    name.push_back(path[i]);
                    i++;
                }
                if(name == ".")
                    continue;
                else if (name == "..")
                {
                    if(!s.empty())
                        s.pop();
                }
                else
                    s.push(name);
            }
        }
        string result = "";
        while(!s.empty())
        {
            result = '/' + s.top() + result;
            s.pop();
        }
        if(result.size())
            return result;
        return "/";
    }
};