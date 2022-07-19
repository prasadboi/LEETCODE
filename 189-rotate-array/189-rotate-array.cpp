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