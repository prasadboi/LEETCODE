class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int curr_tank = 0, tot_tank = 0;
        for(int i = 0; i < n; i++)
        {
            if(curr_tank < 0){curr_tank = 0; start = i;}
            curr_tank += (gas[i] - cost[i]);
            tot_tank += (gas[i] - cost[i]);
        }
        if(tot_tank >= 0) return start; else return -1;
    }
};