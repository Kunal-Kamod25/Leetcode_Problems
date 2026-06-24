#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Tabulation approach (O(n) space)
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Handle edge cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // dp[i] represents the maximum amount of money you can rob up to house i
        vector<int> dp(n, 0);
        
        // Base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        // Tabulation (bottom-up)
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        
        return dp[n - 1];
    }
    
    /* 
    // Space-Optimized Tabulation approach (O(1) space)
    int robOptimized(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; ++i) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
    */
};
