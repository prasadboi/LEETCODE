class MapSum {
public:
    #define umap unordered_map
    #define ll long long int
    #define MOD (ll)(1e9 + 7)
    #define vll vector<ll>
    
    struct node{
        bool isWord;
        umap<char, node*> next;
        node():isWord(false){}
    };
    
    umap<string, ll> M;
    node* root;
    MapSum() {
        root = new node();
    }
    
    
    void insert(string key, int val) {
        node* iter = root;
        for(auto i : key){
            if(iter->next.find(i) == iter->next.end()) iter->next[i] = new node();
            iter = iter->next[i];
        }
        iter->isWord = true;
        M[key] = val;
    }
    
    void dfs(node* i, string w, int &sum){
        if(i->isWord) sum += M[w];
        for(auto j : i->next){
            w.push_back(j.first);
            dfs(j.second, w, sum);
            w.pop_back();
        }
    }
    
    int sum(string prefix) {
        int sum = 0;
        node* iter = root;
        for(auto i : prefix){
            if(iter->next.find(i) == iter->next.end()) return 0;
            iter = iter->next[i];
        }
        dfs(iter, prefix, sum);
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */