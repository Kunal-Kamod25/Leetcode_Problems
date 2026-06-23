class Solution {
public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> cur;

        sort(nums.begin(), nums.end());

        backtrack(0, cur, nums, ans);

        return ans;
    }

    void backtrack(int idx,
                   vector<int>& cur,
                   vector<int>& nums,
                   vector<vector<int>>& ans) {

        if(idx == nums.size()) {
            ans.push_back(cur);
            return;
        }

        // Include nums[idx]
        cur.push_back(nums[idx]);
        backtrack(idx + 1, cur, nums, ans);

        cur.pop_back();

        // Skip duplicates
        while(idx + 1 < nums.size() &&
              nums[idx] == nums[idx + 1]) {
            idx++;
        }

        // Exclude nums[idx]
        backtrack(idx + 1, cur, nums, ans);
    }
};