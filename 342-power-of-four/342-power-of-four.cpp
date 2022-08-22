class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1) return false;
        int set = 0, num0 = 0;
        while(n){if(n&1) set++; else num0++; n = n>>1;}
        if(set == 1 and num0%2 == 0) return true; else return false;
    }
};