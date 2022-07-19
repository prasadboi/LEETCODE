/*
// cycle method
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(),count = 0;
        k %= n;
        for(int start = 0; count < n; start++){
            int curr = start, prev = nums[start];
            do{
                int next = (curr + k)%n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                curr = next;
                count++;
            }while(start != curr);
        }
    }
};
*/

// reverse array method
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        // reverse whole array
        reverse(nums.begin(), nums.end());
        // reverse first k elements
        reverse(nums.begin(), nums.begin() + k);
        // reverse remaining n - k elements
        reverse(nums.begin() + k, nums.end());
    }
};