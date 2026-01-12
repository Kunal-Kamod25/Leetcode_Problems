class Solution {
public:
    int heightChecker(vector<int>& h) {

        int sz=h.size();
        vector<int>e=h;
        sort(e.begin() , e.end());
        int cnt=0;
        for(int i=0 ; i<sz ; i++)
        {
            if(h[i] !=e[i])
            cnt++;
        }
        return cnt;
    }
};