class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int cnt = 0;
        for(int i = 0 ; i < n ; ++i)
        {
            cnt = 0;
            for(int j = 0 ; j < n ; j++)
            {
                if(j !=i && nums [j] < nums [i])
                {
                    cnt ++;
                }
            }
            ans[i] = cnt;
        }
        return ans;
    }
};