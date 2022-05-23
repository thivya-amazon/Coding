// class Solution {
// public:
    // int decodeHelper(int sub_idx, string s)
    // {
//         map<int, int> memo;
//         if(memo.count(sub_idx))
//             return memo[sub_idx];
        
//         if(sub_idx == s.size())
//             return 1;
        
//         if(s[sub_idx] == '0')
//             return 0;
//         if(sub_idx == s.size()-1)
//             return 1;
        
//         //consider 1 digit
//         int count = decodeHelper(sub_idx+1, s);
//         if(stoi(s.substr(sub_idx, 2)) <= 26)
//             count += decodeHelper(sub_idx+2, s);
        
//         memo[sub_idx] = count;
//         return count;
//     }
    
//     int numDecodings(string s) {
//         return decodeHelper(0, s);
//     }
// };
    
class Solution {
public:
    map<int, int> memo;

    int recursiveWithMemo(int index, string& str) {
        // Have we already seen this substring?
        if (memo.find(index) != memo.end()) {
            return memo[index];
        }

        // If you reach the end of the string
        // Return 1 for success.
        if (index == str.length()) {
            return 1;
        }

        // If the string starts with a zero, it can't be decoded
        if (str[index] == '0') {
            return 0;
        }

        if (index == str.length() - 1) {
            return 1;
        }

        int ans = recursiveWithMemo(index + 1, str);
        if (stoi(str.substr(index, 2)) <= 26) {
            ans += recursiveWithMemo(index + 2, str);
        }

        // Save for memoization
        memo[index] = ans;

        return ans;
    }

    int numDecodings(string s) {
        return recursiveWithMemo(0, s);
    }
};