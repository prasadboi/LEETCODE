class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define vb vector<bool>
    #define vi vector<int>
    
    bool workableVal(vi &sweet, ll target, ll k)
    {
        ll ctr = 0, n = sweet.size(), s = 0;
        for(int i = 0; i < n; i++)
        {
            if(s < target) s+= sweet[i];
            if(s >= target){s = 0, ctr++;}
        }
        if(ctr >= (k+1)){return true;}
        else return false;
    }
    
    int maximizeSweetness(vector<int>& sweet, int k) 
    {
        int n = sweet.size();
        if(n < k+1) return 0;
        ll l = INT_MAX, r = 0;
        for(auto i : sweet){
            l = min((ll)i, l);
            r += i;
        }
        r = r/(k+1);
        int res = -1;
        while(l <= r)
        {
            ll m = l + (r-l)/2;
            if(workableVal(sweet, m, k)){res = m; l = m+1;}
            else r = m-1;
        }
        return (int)res;
    }
};