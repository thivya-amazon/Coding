class RandomizedSet {
public:
    //incoming val = key, index of that val in list = value
    unordered_map<int, int> dict;
    vector<int> list;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(dict.count(val))
            return false;
        list.push_back(val);
        dict[val] = list.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(dict.find(val) == dict.end())
            return false;
        int valIdx = dict[val];
        int lastIdx = list.size()-1;
        
        dict[list[lastIdx]] = valIdx;
        dict.erase(val);
        
        swap(list[valIdx], list[lastIdx]);
        list.pop_back();
        
        return true;
    }
    
    int getRandom() {
        return list[rand() % list.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */