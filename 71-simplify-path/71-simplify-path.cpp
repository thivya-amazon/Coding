class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string result;
        for(int index = 0; index < path.size(); index++)
        {
            string name = "";
            if(path[index] != '/')
            {
                while(index < path.size() && path[index] != '/')
                {
                    name.push_back(path[index]);
                    index++;
                }
                
                if(name == ".")
                    continue;
                else if(name == "..")
                {
                    if(!s.empty())
                        s.pop();
                }
                //Actual names
                else
                {
                    s.push(name);
                }
            }               
        }
        
        while(!s.empty())
        {
            result = '/' + s.top() + result;
            s.pop();
        }
        
        return (result.size()) ? result : "/";

    }
};