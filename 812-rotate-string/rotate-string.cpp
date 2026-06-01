class Solution {
public:
    bool rotateString(string s, string goal) {

        string orignal = s;
        for (int i = 0; i < s.length(); i++){

            s = orignal;
            rotate(s.begin(), s.begin() + i, s.end());
            if (s == goal){
                return true;
            }
        }

        return false;
    }
};