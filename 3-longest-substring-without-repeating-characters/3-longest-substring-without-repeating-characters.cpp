class Solution {
public:
    #define vi vector<int>
    #define ll long long int
    #define vll vector<ll>
    
    int lengthOfLongestSubstring(string s) {
        ll l = 0, r = 1, n = s.size();
        vll count(256, 0);

        if(n == 0) return 0;
        ll res = 1;
        count[s[0]]++;
        while(l < n and r < n){
            count[s[r]]++;
            if(count[s[r]] == 2){
                while(l < r and s[l] != s[r]){
                    count[s[l]]--;
                    l++;
                }
                count[s[l]]--; l++;
            }
            // cout<<"l = "<<l<<", r = "<<r<<endl;
            // cout<<"len = "<<r - l + 1<<endl;
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};