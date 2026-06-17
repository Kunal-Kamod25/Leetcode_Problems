class Solution {
public:
    int strStr(string haystack, string needle) {
        int szh = haystack.size();
        int szn = needle.size();

        for(int i = 0; i <= szh - szn; i++) {
            string s1 = haystack.substr(i, szn);

            if(s1 == needle)
                return i;
        }

        return -1;
    }
};