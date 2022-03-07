class Bitset {
public:
   string bits;
    string flipBits;
    int numOnes;
    int total;
    Bitset(int size) {
        bits.resize(size, '0');
        flipBits.resize(size, '1');
        total = size;
        numOnes = 0;
    }
    
    void fix(int idx) {
        if(bits[idx] == '1')
            numOnes--;
        bits[idx] = '1';
        flipBits[idx] = '0';
        numOnes++;            
    }
    
    void unfix(int idx) {
        if(bits[idx] == '1')
            numOnes--;
        bits[idx] = '0';
        flipBits[idx] = '1';
    }
    
    void flip() {
        // for(int idx = 0; idx < bits.size(); idx++)
        // {
        //     if(bits[idx] == 1)
        //     {
        //         numOnes--;
        //         bits[idx] = 0;
        //         str[idx] = '0';
        //     }
        //     else
        //     {
        //         numOnes++;
        //         bits[idx] = 1;
        //         str[idx] = '1';
        //     }
        // }
        swap(bits, flipBits);
        numOnes = total - numOnes;
    }
    
    bool all() {
        if(numOnes == bits.size())
            return true;
        return false;
    }
    
    bool one() {
        if(numOnes > 0)
            return true;
        return false;
    }
    
    int count() {
        return numOnes;
    }
    
    string toString() {
      //  string res(bits.begin(), bits.end());
        return bits;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */