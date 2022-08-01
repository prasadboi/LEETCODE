/*
failed atttempt
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ctr0 = 0, ctr1 = 0;
        int l = 0, r = nums.size()-1;
        for(auto i : nums) if(i) ctr1++; else ctr0++;
        while(ctr1 != ctr0){
            cout<<"l = "<<l<<"r = "<<r<<", ctr0 = "<<ctr0<<", ctr1 = "<<ctr1<<endl;
            if(ctr0 > ctr1){
                if(!nums[l] or !nums[r]){
                    if(!nums[l]) l++; else r--;
                    ctr0--;
                }
                else{l++, ctr1--;}
            }
            else if(ctr1 > ctr0){
                if(nums[l] or nums[r]){
                    if(nums[l]) l++; else r--;
                    ctr1--;
                }
                else l++, ctr0--;
            }
        }
        return r - l  +1;
    }
};
*/

class Solution {
public:
    #define vi vector<int>
    #define umap unordered_map
    int findMaxLength(vector<int>& nums) {
        umap<int, int> count; // a hashmap that stores the count (1s - 0s)
        // peaks and valley problem bolte
        int ctr = 0, res = 0;
        for(auto i = 0; i < nums.size(); i++)
        {
            if(nums[i]) ctr++; else ctr--;
            if(ctr == 0) res = max(i + 1, res);
            if(count.find(ctr) != count.end()) res = max(i - count[ctr], res);
            else count[ctr] = i;
        }
        return res;
    }
};