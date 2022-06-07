// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#define ll long long int
class Solution {
public:
    int firstBadVersion(int n) 
    {
        ll l = 1, r = n;
        while(l < r)
        {
            ll m = l + (r-l)/2;
            if(isBadVersion(m) == false) l = m+1;
            else r = m;
        }
        if(l != (ll)n+1 and isBadVersion(l) == true) return l;
        return -1;
    }
};