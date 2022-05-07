class Solution {
public:
    string dict[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    void combHelper(int sub_idx, string& slate, string& digits)
    {
        if(sub_idx == digits.size())
        {
            if(slate.size())
                result.push_back(slate);
            return;
        }
        int digit = digits[sub_idx] - '0';
        string letters = dict[digit];
        for(int i = 0; i < letters.size(); i++)
        {
            slate.push_back(letters[i]);
            combHelper(sub_idx+1, slate, digits);
            slate.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string slate = "";
        combHelper(0, slate, digits);
        return result;
    }
};