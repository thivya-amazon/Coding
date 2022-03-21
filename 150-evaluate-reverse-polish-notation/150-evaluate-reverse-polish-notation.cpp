class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> op;
        stack<int> res;
        if(tokens.size() < 3)
            return stoi(tokens[0]);
            
        for(int i = 0; i < tokens.size(); i++)
        {
            int opResult = 0;
            if(!res.empty())
            {
                opResult = res.top();
                op.push(opResult);
                res.pop();
            }               
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
                int elem = stoi(tokens[i]);
                op.push(elem);
            }
            else
            {
                int operand2 = op.top();
                op.pop();
                int operand1 = op.top();
                op.pop();
                
                switch(tokens[i][0])
                {
                    case '+':
                        opResult = operand1 + operand2;
                        break;
                        
                    case '-':
                        opResult = operand1 - operand2;
                        break;
                        
                    case '*':
                        opResult = operand1 * operand2;
                        break;
                        
                    case '/':
                        opResult = operand1 / operand2;
                        break;
                        
                    default:
                        break;                        
                }
                res.push(opResult);
            }
    
        }
        return res.top();
    }
};