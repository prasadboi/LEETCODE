class LRUCache {
public:
    #define ll long long int
    #define umap unordered_map
    
    list<pair<ll, ll>> LRU; // stores the LRU item in a list style
    umap<ll, list<pair<ll, ll>>::iterator> cache; // stores the list iterator assoc with a key
    ll cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            // the key is available
            LRU.splice(LRU.begin(), LRU, cache[key]);
            return cache[key]->second;
        }
        else return -1;
    }
    
    void put(int key, int value) 
    {
        if(cache.find(key) != cache.end()){
            // if the key isin the LRU range then simply update value and make it most recently used item
            cache[key]->second = value;
            LRU.splice(LRU.begin(), LRU, cache[key]);
        }
        else
        {
            // if key has not been encountered earlier
            if(cache.size() == cap){
                // first make space for entering one key-val pair into the list
                pair<ll, ll> LRU_item = LRU.back(); LRU.pop_back();
                // if not in list then must not be in cache also
                cache.erase(LRU_item.first);
            }
            pair<ll, ll> new_item = {key, value};
            LRU.push_front(new_item);
            cache[key] = LRU.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */