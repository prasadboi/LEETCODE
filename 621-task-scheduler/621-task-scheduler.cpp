class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> M;
        int maxfreq = 0;
        for(auto i : tasks){M[i]++; maxfreq = max(maxfreq, M[i]);}
        int ans = (maxfreq-1)*(n+1);
        for(auto i : M) if(i.second == maxfreq) ans++;
        return max((int)tasks.size(), ans);
    }
};