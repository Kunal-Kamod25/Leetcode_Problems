#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function using Memoization (Top-Down DP)
    int solveMem(vector<int>& nums, int currentIndex, int endIndex, vector<int>& memo) {
        // Base case: if we've moved past the last available house, no more money to rob
        if (currentIndex > endIndex) {
            return 0;
        }
        
        // If we have already calculated the result for this state, return it
        if (memo[currentIndex] != -1) {
            return memo[currentIndex];
        }
        
        // Option 1: Rob the current house and move to the house after next
        int robCurrent = nums[currentIndex] + solveMem(nums, currentIndex + 2, endIndex, memo);
        
        // Option 2: Skip the current house and move to the next house
        int skipCurrent = solveMem(nums, currentIndex + 1, endIndex, memo);
        
        // Store the result in memo and return
        return memo[currentIndex] = max(robCurrent, skipCurrent);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Handle edge cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // We need two separate memoization arrays because the states are different
        // since they have different end boundaries.
        vector<int> memo1(n, -1);
        vector<int> memo2(n, -1);
        
        // Scenario 1: Rob from index 0 to n-2 (excluding the last house)
        int maxExcludingLast = solveMem(nums, 0, n - 2, memo1);
        
        // Scenario 2: Rob from index 1 to n-1 (excluding the first house)
        int maxExcludingFirst = solveMem(nums, 1, n - 1, memo2);
        
        return max(maxExcludingLast, maxExcludingFirst);
    }
};
