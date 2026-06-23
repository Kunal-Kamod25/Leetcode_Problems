class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(0 , cur , nums , ans);
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

        cur.push_back(nums[idx]);
        backtrack(idx + 1 , cur , nums , ans);

        cur.pop_back();
        backtrack(idx + 1 , cur , nums , ans);
    }
};