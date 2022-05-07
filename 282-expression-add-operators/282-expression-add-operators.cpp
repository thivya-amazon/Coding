class Solution {
public:
    vector<string> result;
    void expHelper(int sub_idx, string& slate, const string& num, long long currVal, long long numAfterSum, long long target)
    {
        if(sub_idx == num.size())
        {
            if(target == currVal)
                result.push_back(slate);
            return;
        }
        for(int i = sub_idx; i < num.size(); i++)
        {
            string current = num.substr(sub_idx, i-sub_idx+1);
            if(current[0] == '0' && i != sub_idx)
                break;
           long long number = stoll(current);
            if(sub_idx == 0)
            {
                slate.append(current);
                expHelper(i+1, slate, num, number, number, target);
                for(int i = 0; i < current.size(); i++)
                    slate.pop_back();
            }
            else
            {
                slate.push_back('+');
                slate.append(current);
                expHelper(i+1, slate, num, currVal+number, number, target);
                for(int i = 0; i < current.size(); i++)
                    slate.pop_back();
                slate.pop_back();
                
                slate.push_back('-');
                slate.append(current);
                expHelper(i+1, slate, num, currVal-number, -number, target);
                for(int i = 0; i < current.size(); i++)
                    slate.pop_back();
                slate.pop_back();
                
                slate.push_back('*');
                slate.append(current);
                expHelper(i+1, slate, num, (currVal-numAfterSum) + (numAfterSum*number), (numAfterSum*number), target);
                for(int i = 0; i < current.size(); i++)
                    slate.pop_back();
                slate.pop_back();
            }
                
        }
    }
    vector<string> addOperators(string num, int target) {
        string slate = "";
        expHelper(0, slate, num, 0, 0, target);
        return result;

    }
};