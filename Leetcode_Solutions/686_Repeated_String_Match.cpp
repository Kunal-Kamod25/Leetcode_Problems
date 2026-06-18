class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int sza = a.size();
        int szb = b.size();

        int cnt = 0;
        string s = "";

        while(s.size() < szb) {
            s += a;
            cnt++;
        }

        if(s.find(b) != string::npos)
            return cnt;

        s += a;
        cnt++;

        if(s.find(b) != string::npos)
            return cnt;

        return -1;
    }
};