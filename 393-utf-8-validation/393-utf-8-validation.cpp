class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        int bytesToProcess = 0;
        
        for(int i = 0; i < n; i++)
        {
            //first byte
            if(bytesToProcess == 0)
            {
                int firstByteMask = 1 << 7;
                while(data[i] & firstByteMask)
                {
                    bytesToProcess++;
                    firstByteMask >>= 1;                   
                }
                if(bytesToProcess == 0)
                    continue;
                if(bytesToProcess == 1 || bytesToProcess > 4)
                    return false;
            }
            else
            {
                int bit1Mask = 1 << 7;
                int bit2Mask = 1 << 6;
                if(!((data[i] & bit1Mask) != 0 && (data[i] & bit2Mask) == 0))
                    return false;                
            }
            bytesToProcess--;
        }
        return bytesToProcess == 0;
        
    }
};