class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() <= 1)
            return chars.size();
        int count = 0;
        int charIdx = -1;
        for(int i = 0; i < chars.size(); )
        {
            int index = i + 1;
            int charCount = 1;
            while(index < chars.size() && chars[i] == chars[index])
            {
                index++;
                charCount++;
            }
            chars[++charIdx] = chars[i];
            if(charCount > 1)
            {
                if(charCount > 9)
                {
                    vector<char> temp;
                    while(charCount > 0)
                    {
                        temp.push_back(charCount % 10 + '0');
                        charCount /= 10;
                    }
                    reverse(temp.begin(), temp.end());
                    for(int j = 0; j < temp.size(); j++)
                        chars[++charIdx] = temp[j];
                    count = count + 1 + temp.size();
                }
                else
                {
                    chars[++charIdx] = charCount + '0';
                    count += 2;
                }

            }
            else
                count++;           
            i = index;
            
        }
        return count;
    }
};