class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(auto i : nums) arr.push_back(to_string(i));
        
        auto cmp = [](string &a, string &b)
        {
            return a+b < b+a;
        };
        
        sort(arr.begin(), arr.end(), cmp);
        // for(auto i : arr) cout<<i<<" - "; cout<<endl;
        string res;
        for(int i = arr.size()-1; i >= 0; i--)
            res = res + arr[i];
        return (res.front() == '0') ? "0" : res;
    }
};