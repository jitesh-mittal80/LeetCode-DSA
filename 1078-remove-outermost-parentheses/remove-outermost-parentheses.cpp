class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int bal = 0;

        for (char ch: s){
            if (ch == '('){
                if (bal > 0){
                    ans = ans + ch;
                }
                bal++;
            }
            else{
                bal--;
                if (bal>0){
                    ans = ans + ch;
                }
            }
        }

        return ans;
    }
};