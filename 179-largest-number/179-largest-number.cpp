    bool compare(string a, string b)
    {
        return a+b > b+a;
    }

class Solution {
public:

    string largestNumber(vector<int>& nums) {
        vector<string> numsString;
        string result;
        for(auto n : nums)
            numsString.push_back(to_string(n));
        sort(numsString.begin(), numsString.end(), compare);
                
        for(auto s : numsString)
            result += s;
        
        if(result[0] == '0')
            return "0";
        return result;
    }
};