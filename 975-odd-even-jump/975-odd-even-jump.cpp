class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n  = A.size(), res = 1;
        
        vector<bool> higher(n, false), lower(n, false);
        higher[n - 1] = lower[n - 1] = 1;
        
        map<int, int> map;
        map[A[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            auto hi = map.lower_bound(A[i]), lo = map.upper_bound(A[i]);
            if (hi != map.end()) higher[i] = lower[hi->second]; // smallest value larger than target
            if (lo != map.begin()) lower[i] = higher[(--lo)->second]; // largest index less than current value
            
            if (higher[i]) res++;
            map[A[i]] = i;
        }
        return res;
    }
};