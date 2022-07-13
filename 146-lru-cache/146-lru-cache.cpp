/*
class LRUCache {
public:
//  LEAST RECENTLY USED CACHE
    unordered_map<int, int> cache;
    map<int, int> LRU;
    int cap;
    int ctr;
    LRUCache(int capacity) {
        cap = capacity;
        ctr = 0;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            LRU[key] = ctr++;
            return cache[key];
        }
        else return -1;
    }
    
    void put(int key, int value) {
        // cout<<"pushed : "<<key<<" - "<<value<<endl;
        cache[key] = value;
        LRU[key] = ctr++;
        int lru_id = min_element(LRU.begin(), LRU.end(), [](const auto &a, const auto &b){return a.second < b.second;})->first;
        if(cache.size() <= cap) return;
        // cout<<"lruid is : "<<lru_id<<endl;
        cache.erase(lru_id);
        LRU.erase(lru_id);
    }
};

*/

class LRUCache {
public:
    list<pair<int, int>> LRU;
    map<int, list<pair<int, int>>::iterator> cache; // cache[k] points to an iterator of a list
    int cap;
    
    LRUCache(int capacity) {
        LRU.clear();
        cache.clear();
        cap = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        else{
            LRU.splice(LRU.begin(), LRU, cache[key]);
            // cout<<"found key : "<<cache[key]->second<<endl;
            return cache[key]->second;
        }
    }
    
    void put(int key, int value) {
        // cout<<"putting key - value"<<key<<"-"<<value<<endl;
        if(cache.find(key) != cache.end()){
            LRU.splice(LRU.begin(), LRU, cache[key]);
            cache[key]->second = value;
        }
        else{
            if(cache.size() == cap){
                auto delete_key = LRU.back().first;
                LRU.pop_back();
                cache.erase(delete_key);
            }
            LRU.push_front({key, value});
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