class Solution {
public:
    string toHex(int n) {
        unsigned int num = n;
        string result = "";
        if(num == 0)
        {
            result += "0";
            return result;
        }
        else if(num < 0)
        {
            num = (~num + 1);
        }

        while(num)
        {
            int lsb = num % 16;
            if(lsb < 10)
                result.push_back(lsb +'0');
            else
            {
                switch(lsb)
                {
                    case 10:
                        result.push_back('a');
                        break;
                    case 11:
                        result.push_back('b');
                        break;
                    case 12:
                        result.push_back('c');
                        break;
                    case 13:
                        result.push_back('d');
                        break;
                    case 14:
                        result.push_back('e');
                        break;
                    case 15:
                        result.push_back('f');
                        break;
                }
            }
            num /= 16;
        }
        reverse(result.begin(), result.end());
        return result;
           
    }
};