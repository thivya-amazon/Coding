class Solution {
public:

    int temp;
    vector<int> diffWaysToCompute(string exp) {
        vector<int> result;
        vector<int> left;
        vector<int> right;
        if(exp.find('+') == -1 && exp.find('-') == -1 && exp.find('*') == -1)
        {
            stringstream(exp) >> temp;
            result.push_back(temp);
            return result;
        }
        
        for(int i = 1; i < exp.size(); i++)
        {
            if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*')
            {
                left = diffWaysToCompute(exp.substr(0, i));
                right = diffWaysToCompute(exp.substr(i+1));
                for(int j = 0; j < left.size(); j++)
                    for(int k = 0; k < right.size(); k++)
                    {
                        int val = 0;
                        if(exp[i] == '+') val = left[j] + right[k]; 
                        else if(exp[i] == '-') val = left[j] - right[k]; 
                        else if(exp[i] == '*') val = left[j] * right[k]; 
                        result.push_back(val);
                    }
            }
        }
        return result;
    }
};