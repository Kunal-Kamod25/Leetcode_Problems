class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n= nums.size();
        for(int i=0 ; i<n ; i++)
        {
            for(int j=i+1 ; j<n ; j++)
            {
                if(nums[i] + nums[j]==target)
                {
                    ans.push_back(i); //ans[0]=i;
                    ans.push_back(j); //ans[j]=j;
                    return ans;
                }
            }
        }
        return ans;
    }
};