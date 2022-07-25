class Solution {
public:
    #define vi vector<int>
    #define vll vector<ll>
    #define umap unordered_map
    
    int minDeletions(string s) {
        stack<int> availFreqs;
        vi freq(26, 0);
        for(auto i : s) freq[i - 'a']++;
        
        int res = 0;
        sort(freq.begin(), freq.end());
        while(freq.size() and freq.front() == 0) freq.erase(freq.begin());
        // for(auto i : freq) cout<<i<<" "; cout<<endl; 
        int i = 0, j = 0;
        for(; i <= freq.back() and j < freq.size(); i++){
            // cout<<"i = "<<i<<", freq[j] = "<<freq[j]<<endl;
            if(i < freq[j]) availFreqs.push(i);
            if(i == freq[j]) j++;
            while(j > 0 and j < freq.size() and freq[j] == freq[j-1]){
                // cout<<"j = "<<j<<", freq[j] = "<<freq[j]<<", freq[j-1] = "<<freq[j-1]<<endl;
                if(availFreqs.size() == 0) res += freq[j];
                else{res += (freq[j] - availFreqs.top()); availFreqs.pop();}
                j++;
            }
        }
        
        return res;
    }
};