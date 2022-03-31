class LRUCache {
public:
    int cacheSize;
    list<pair<int,int>> cache;
    map<int, list<pair<int,int>>::iterator> keyMap;
    LRUCache(int capacity) {
        cacheSize = capacity;
    }
    void addToFront(int key, int value)
    {
        cache.push_front({key, value});
        keyMap[key] = cache.begin();
    }
    int get(int key) {
        map<int, list<pair<int,int>>::iterator> :: iterator it = keyMap.find(key);
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
        map<int, list<pair<int,int>>::iterator> :: iterator it = keyMap.find(key);
        if(it != keyMap.end())
        {
            cache.erase(it->second);
            addToFront(key, value);
        }
        else
        {
            if(cache.size() == cacheSize)
            {
                int lruKey = cache.back().first;
                cache.pop_back();
                keyMap.erase(lruKey);
            }
            addToFront(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */