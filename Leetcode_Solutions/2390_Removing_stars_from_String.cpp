#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;

        for(int i = 0; i < s.size(); i++) {
            char cur = s[i];
            if(cur == '*') {
                stk.pop();
            } else {
                stk.push(cur);
            }
        }

        string ans = "";
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter string: ";
    cin >> s;

    string result = obj.removeStars(s);
    cout << "Result: " << result << endl;

    return 0;
}