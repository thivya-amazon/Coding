class LRUCache {
public:
    list<pair<int,int>> cache;
    map<int, list<pair<int,int>>::iterator> keyMap;
    int maxCap;
    LRUCache(int capacity) {
        maxCap = capacity;
    }
    void addToFront(int key, int value)
    {
        cache.push_front({key,value});
        keyMap[key] = cache.begin();
    }
    int get(int key) {
        map<int, list<pair<int,int>> :: iterator> :: iterator it = keyMap.find(key);
        if(it != keyMap.end())
        {
            int value = it->second->second;
            cache.erase(it->second);
            addToFront(key, value);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        map<int, list<pair<int,int>> :: iterator> :: iterator it = keyMap.find(key);
        if(it != keyMap.end())
        {
            cache.erase(it->second);
        }
        else
        {
            if(keyMap.size() == maxCap)
            {
                int lruKey = cache.back().first;
                keyMap.erase(lruKey);
                cache.pop_back();
            }
        }
         addToFront(key,value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */