class Solution {
public:
    #define uset unordered_set
    #define umap unordered_map
    
    int longestConsecutive(vector<int>& nums) {
        uset<int> seq;
        for(auto i : nums) seq.insert(i);
        
        int res = 0;
        for(auto i : seq)
        {
            int len = 1;
            for(int j = i; seq.find(j-1) != seq.end(); j--){seq.erase(j-1); len++;}
            for(int j = i; seq.find(j+1) != seq.end(); j++){seq.erase(j+1); len++;}
            res = max(res, len);
        }
        return res;
    }
};