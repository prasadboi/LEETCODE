#define ll long long int
#define vi vector<int>
#define umap unordered_map
struct node{
    bool isWord;
    umap<char, node*> next;
};

class Trie {
private: 
    node* root;
public:
    
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* p = root;
        for(char i : word){
            if((p->next).count(i) <= 0){
                p->next[i] = new node();
            }
            p = p->next[i];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        node* p = root;
        for(auto i : word){
            if((p->next).count(i) <= 0) return false;
            p = (p->next)[i];
        }
        return p->isWord;
    }
    
    bool startsWith(string prefix) {
        node* p = root;
        for(auto i : prefix){
            if((p->next).count(i) <= 0) return false;
            p = (p->next)[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */