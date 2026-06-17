#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int sz = s.size();

        for(int i = 0; i < sz / 2; i++) {
            int len = i + 1;

            if(sz % len != 0)
                continue;

            int rep = sz / len;

            string s1 = s.substr(0, len);
            string s2;

            for(int j = 0; j < rep; j++) {
                s2 += s1;
            }

            if(s2 == s)
                return true;
        }

        return false;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter string: ";
    cin >> s;

    if(obj.repeatedSubstringPattern(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}