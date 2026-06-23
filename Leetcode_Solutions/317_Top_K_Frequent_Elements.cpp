class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> ht;

        for(auto e : nums)
            ht[e]++;

        priority_queue<pair<int, int>> heap;

        for(auto e : ht)
            heap.push({e.second, e.first});

        vector<int> ans;

        for(int i = 0; i < k; i++) {

            auto [freq, num] = heap.top();

            heap.pop();

            ans.push_back(num);
        }

        return ans;
    }
};