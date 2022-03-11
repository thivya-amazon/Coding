class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string result;
        
        int n1 = num1.size();
        int n2 = num2.size();
        
        if(n1 > n2)
        {
            for(int i = 0; i < n1-n2; i++)
            {
                num2.push_back('0');
            }
        }
        else
        {
            for(int i = 0; i < n2-n1; i++)
            {
                num1.push_back('0');
            }
        }
        
        int maxLength = max(n1, n2);
        int carry = 0;
        for(int i = 0; i < maxLength; i++)
        {
            char x = (num1[i]) ? num1[i] : '0';
            char y = (num2[i]) ? num2[i] : '0';
            cout << "x =" << x << "," << "y=" << y<< endl;
            int sum = (x -'0') + (y -'0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            cout << sum << endl;
            result.push_back(sum + '0');
        }
        if(carry)
            result.push_back(carry + '0');
        reverse(result.begin(), result.end());
        return result;
    }
};