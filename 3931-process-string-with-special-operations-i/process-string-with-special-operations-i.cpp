class Solution {
public:
    string processStr(string s) {
        string result = "";
        
        for (int i = 0; i < s.size(); i++){
            if (islower(s[i])){
                result = result + s[i];
            }

            else if (s[i] == '*'){
                if (result.empty()){
                    continue;
                }

                else{
                    result.pop_back();
                }
            }

            else if (s[i] == '#'){
                result  = result + result;
            }

            else if (s[i] == '%'){
                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};