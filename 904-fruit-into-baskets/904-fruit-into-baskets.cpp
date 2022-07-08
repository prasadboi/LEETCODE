class Solution {
public:
    // sliding window algo for k unique elements in the window always
    int totalFruit(vector<int>& tree) {
        if(tree.size() == 0) return 0;
        unordered_map<int, int> count;
        int l, r;
        int res = 1;
        for (l = 0, r = 0; r < tree.size(); r++) {
            count[tree[r]]++;
            if (count.size() > 2) {
                if (--count[tree[l]] == 0)count.erase(tree[l]);
                l++;
            }
            if(count.size() <= 2) res = max(res, r - l + 1);
        }
        return  res;
    }
};