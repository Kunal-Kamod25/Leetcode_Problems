    class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int>stk;
            for(const string& t: tokens){
                if(t =="+" || t =="-" || t =="*" || t =="/") {
                    int rtg = stk.top() ; stk.pop();
                    int lft = stk.top() ; stk.pop();
                    int ans = 0;

                    if(t=="+") ans = lft + rtg;
                    else if(t=="-") ans = lft - rtg;
                    else if(t=="*") ans = lft * rtg;
                    else if(t=="/") ans = lft / rtg;

                    stk.push(ans);
                }
                else{
                    stk.push(stoi(t));
                }
            }
            return stk.top();
            
        }
    };