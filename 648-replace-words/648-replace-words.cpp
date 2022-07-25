class Solution {
public:
    #define ll long long int
    #define umap unordered_map
    #define vb vector<bool>
    #define vi vector<int>
    #define vll vector<ll>
    #define vvll vector<vll>
    
    struct node
    {
        bool isRoot;
        umap<char, node*> next;
        node():isRoot(false){}
    };
    
    node* root = new node;
    
    void insertRoot(string word)
    {
        node* iter = root;
        for(auto i : word){
            if(iter->next.count(i) <= 0) iter->next[i] = new node();
            iter = iter->next[i];
        }
        iter->isRoot = true;
    }
    
    string getRoot(string word)
    {
        node* iter = root; string prefix;
        for(auto i : word)
        {
            if(iter->isRoot == true) return prefix;
            if(iter->next.count(i) <= 0) return word;
            prefix.push_back(i);
            iter = iter->next[i];
        }
        return word;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(auto str : dictionary) insertRoot(str);
        
        stringstream ss(sentence);
        string word;
        string res;
        while(getline(ss, word, ' ')){
            // cout<<"word is : "<<word<<endl;
            res += getRoot(word) + " ";
        }
        res.pop_back();
        return res;
    }
};