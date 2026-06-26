class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cur_max = nums[0];
        int cur_min = nums[0];
        int best = nums[0];

        for (int i = 1; i < (int)nums.size(); i++) {
            int x = nums[i];

            int a = x * cur_max;
            int b = x * cur_min;

            int newMax = max(x, max(a, b));
            int newMin = min(x, min(a, b));

            cur_max = newMax;
            cur_min = newMin;

            best = max(best, cur_max);
        }

        return best;
    }
};