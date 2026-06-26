class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int sz = prices.size();

        if (sz == 1)
            return 0;

        int mini = prices[0];

        for (int i = 1; i < sz; i++) {
            maxProfit = max(maxProfit, prices[i] - mini);
            mini = min(mini, prices[i]);
        }

        return maxProfit;
    }
};