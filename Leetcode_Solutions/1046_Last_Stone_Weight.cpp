class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int sz = stones.size();
        if(sz == 1)
            return stones[0];
        
        priority_queue<int> heap(stones.begin() , stones.end());
        while(heap.size() > 1) {
            int h = heap.top();
            heap.pop();

            int l = heap.top();
            heap.pop();

            if(h != l)
                heap.push(h - l);
        }
        return heap.size() == 0? 0:heap.top();
    }
};