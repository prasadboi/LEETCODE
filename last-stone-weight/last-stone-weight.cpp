class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap(stones.begin(), stones.end());
        while(maxheap.size() > 1){
            int stone1 = maxheap.top(); maxheap.pop();
            int stone2 = maxheap.top(); maxheap.pop();
            int wtloss = min(stone1, stone2);
            if(stone1 - wtloss > 0) maxheap.push(stone1 - wtloss);
            if(stone2 - wtloss > 0) maxheap.push(stone2 - wtloss);
        }
        if(maxheap.size()) return maxheap.top(); else return 0;
    }
};