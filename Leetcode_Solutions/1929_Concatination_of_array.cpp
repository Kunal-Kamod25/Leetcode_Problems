class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
     int sz = nums.size();
     vector<int> ans (2*sz);

     for(int i = 0 ; i < sz ; i++)
     {
        ans[i] = nums[i];
        ans[i+sz] = nums[i];
     }   
     return ans;
    }
};