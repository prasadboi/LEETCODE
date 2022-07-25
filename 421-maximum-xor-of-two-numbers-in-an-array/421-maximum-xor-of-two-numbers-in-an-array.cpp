class Solution {
public:
    #define umap unordered_map
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define vi vector<int>
    
    struct node{
        bool isVal; vector<node*> next;
        node():isVal(false), next(2, NULL) {}
    };
    
    class BITWISE_TRIE
    {
    private: 
        node* root;
    public:
        void insertNum(int num){
            bitset<32> B(num);
            node* iter = root;
            for(auto i = 31; i >= 0; i--){
                if(!iter->next[B[i]]) iter->next[B[i]] = new node();
                iter = iter->next[B[i]];
            }
            iter->isVal = true;
            // cout<<"inserted number = "<<num<<" successfully\n";
        }
        BITWISE_TRIE(vi &nums){
            root = new node();
            for(auto i : nums) insertNum(i);
        }
        
        int findMaxXOR(int num){
            node* iter = root;
            bitset<32> B(num);
            int ans = 0;
            for(auto i = 31; i >= 0; i--){
                if(iter->next[!B[i]]) ans += (1<<i), iter = iter->next[!B[i]];
                else iter = iter->next[B[i]];
            }
            return ans;
        }
    };
    
    
    int findMaximumXOR(vector<int>& nums) {
        // use a bitwise trie to store all the numbers
        BITWISE_TRIE bt(nums);
        int maxXOR = 0;
        for(auto i : nums) maxXOR = max(maxXOR, bt.findMaxXOR(i));
        return maxXOR;
    }
};