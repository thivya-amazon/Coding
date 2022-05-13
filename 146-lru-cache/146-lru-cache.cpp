class LRUCache {
public:
    list<pair<int,int>> tracker;
    map<int, list<pair<int,int>>::iterator> cache;
    int maxCap;
    LRUCache(int capacity) {
        maxCap = capacity;
    }
    void addToFront(int key, int value)
    {
        tracker.push_front({key,value});
        cache[key] = tracker.begin();
    }
    int get(int key) {
        map<int, list<pair<int,int>> :: iterator> :: iterator it = cache.find(key);
        if(it != cache.end())
        {
            int value = it->second->second;
            tracker.erase(it->second);
            addToFront(key, value);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        map<int, list<pair<int,int>> :: iterator> :: iterator it = cache.find(key);
        if(it != cache.end())
        {
            tracker.erase(it->second);
        }
        else
        {
            if(cache.size() == maxCap)
            {
                int lruKey = tracker.back().first;
                cache.erase(lruKey);
                tracker.pop_back();
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