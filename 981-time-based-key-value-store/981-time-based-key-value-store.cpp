class TimeMap {
public:
    map<string, map<int, string>> M;
    TimeMap() {
        M.clear();
    }
    
    void set(string key, string value, int timestamp) {
        M[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(M.find(key) == M.end()) return "";
        auto it = M[key].lower_bound(timestamp);
        if((*it).first == timestamp) return (*it).second;
        else{
            // *it = {timestamp, value};
            if(it != M[key].begin()){--it; return (*it).second;}
            else return "";
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */