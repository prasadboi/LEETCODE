class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(auto i : asteroids)
        {
            if(i >= 0) s.push(i);
            else{
                while(s.size() and abs(i) > s.top() and s.top() > 0) s.pop();
                if(s.size() == 0) s.push(i);
                else if(s.top() == abs(i)) s.pop();
                else if(s.top() < 0) s.push(i);
            }
        }
        vector<int> res;
        while(s.size()){res.push_back(s.top()); s.pop();}
        reverse(res.begin(), res.end());
        return res;
    }
};