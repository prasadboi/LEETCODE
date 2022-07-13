class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(auto i : tasks) freq[i - 'A']++;
        sort(freq.begin(), freq.end());
        int fmax = freq[25]; freq.pop_back();
        int idle_time = (fmax-1)*(n);
        while(idle_time and freq.size())
        {
            idle_time -= min(fmax - 1, freq.back());
            freq.pop_back();
            idle_time = max(0, idle_time);
        }
        return idle_time + tasks.size();
    }
};