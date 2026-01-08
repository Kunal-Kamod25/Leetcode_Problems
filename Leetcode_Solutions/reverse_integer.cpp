class Solution {
public:
    int reverse(int x) {
        int ans=0;
        int MAX=INT_MAX/10 , MIN=INT_MIN/10;
        while (x!=0)
        {
            if(MAX < ans || MIN > ans)
                return 0;
            ans = ans * 10 + (x % 10);
            x=x/10;
        }
        return ans;
    }
};