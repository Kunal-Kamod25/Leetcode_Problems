class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int sz = nums.size();

        if(sz < k)
            return 0;

        priority_queue<int> heap(nums.begin(), nums.end());

        int ans = 0;

        for(int i = 0; i < k; i++) {

            ans = heap.top();

            heap.pop();
        }

        return ans;
    }
};