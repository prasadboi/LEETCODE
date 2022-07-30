/*
    
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        for(auto s : words1){
            umap<char, ll> s_freq;
            for(auto i : s) s_freq[i]++;
            bool flag = true;
            for(auto sub : words2){
                umap<char, ll> sub_freq;
                for(auto i : sub){sub_freq[i]++; if(sub_freq[i] > s_freq[i]){flag = false; break;}}
                if(!flag) break;
            }
            if(flag) res.push_back(s);
        }
        return res;
    }
};
*/


class Solution {
public:
    #define umap unordered_map
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vvll sfreq(words1.size(), vll(26, 0));
        vll subfreq(26,0);
        for(auto i = 0; i < words1.size(); i++){
            for(auto j : words1[i]) sfreq[i][j - 'a']++;
        }
        for(auto i = 0; i < words2.size(); i++){
            umap<ll, ll> temp;
            for(auto j : words2[i]) 
            {
                temp[j - 'a']++;
                subfreq[j-'a'] = max(subfreq[j-'a'], temp[j - 'a']);
            }
        }
        
        for(auto i = 0; i < words1.size(); i++){
            bool flag = true;
            for(auto j = 0; j < 26; j++){
                if(sfreq[i][j] < subfreq[j]){flag = false; break;}
            }
            if(flag) res.push_back(words1[i]);
        }
        return res;
        
    }
};