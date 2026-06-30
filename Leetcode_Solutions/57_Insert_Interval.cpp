class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //step1
        vector<vector<int>> I2;

        for (auto i : intervals) {
            I2.push_back(i);
        }

        I2.push_back(newInterval);

        //step 2
        sort(I2.begin(), I2.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            });

        //step 3
        int sz = I2.size();

        int start = I2[0][0];
        int end = I2[0][1];

        vector<vector<int>> ans;

        for(int i = 1; i < sz; i++) {
            if(I2[i][0] <= end) {
                end = max(end, I2[i][1]);
            }
            else {
                ans.push_back({start, end});

                start = I2[i][0];
                end = I2[i][1];
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};