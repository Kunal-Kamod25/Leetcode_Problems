class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();

        // Step 1: Create count array
        vector<int> count(n + 1, 0);

        // Step 2: Count occurrences
        for (int num : nums) {
            count[num]++;
        }

        int duplicate = -1, missing = -1;

        // Step 3: Find duplicate and missing
        for (int i = 1; i <= n; i++) {
            if (count[i] == 2)
                duplicate = i;
            else if (count[i] == 0)
                missing = i;
        }

        return {duplicate, missing};
    }
};