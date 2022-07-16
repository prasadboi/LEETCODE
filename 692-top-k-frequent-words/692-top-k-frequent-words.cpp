class Solution {
public:
    unordered_map<string, int> freq;
    vector<string> topKFrequent(vector<string>& words, int k) {
        for(auto i : words) freq[i]++;
        auto cmp = [](pair<string, int> &a, pair<string, int> &b){
            if(a.second < b.second) return true;
            else if(a.second > b.second) return false;
            else if(a.second == b.second){
                for(auto i = 0; i < min(a.first.size(), a.first.size()); i++)
                {
                    if(a.first[i] > b.first[i]) return true;
                    else if(a.first[i] < b.first[i]) return false;
                }
            }
            return false;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> maxheap(cmp);
        for(auto i : freq)
            maxheap.push({i.first, i.second});
        vector<string> res;
        while(k-- and maxheap.size()){
            // cout<<"maxheap.top.first = "<<maxheap.top().first<<", freq = "<<maxheap.top().second<<endl;
            res.push_back(maxheap.top().first); maxheap.pop();
        }
        return res;
    }
};