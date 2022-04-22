class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        while(num)
        {
            for(int i = 0; i < symbol.size(); i++)
            {
                if(num >= value[i])
                {
                    roman += symbol[i];
                    num -= value[i];
                    break;
                }
            }
        }
        return roman;
    }
};