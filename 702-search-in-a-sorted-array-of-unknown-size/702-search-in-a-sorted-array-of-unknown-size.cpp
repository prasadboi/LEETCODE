/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    #define ll long long int
    int search(const ArrayReader& reader, int target) 
    {
        ll n = 1e4, l = 0, r = n-1;
        while(l <= r)
        {
            ll m = l + (r-l)/2;
            // cout<<"m = "<<m<<", l = "<<l<<", r = "<<r<<endl;
            if(reader.get(m) == target) return m;
            else if(reader.get(m) < target) l = m+1;
            else r = m-1;
        }
        return -1;
    }
};