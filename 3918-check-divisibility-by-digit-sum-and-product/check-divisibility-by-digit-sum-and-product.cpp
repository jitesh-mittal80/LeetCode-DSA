class Solution {
public:
    bool checkDivisibility(int n) {
        if(n <= 9){
            return false;
        }
        int pr = 1;
        int sum = 0;

        string s = to_string(abs(n));
        for(auto i = 0; i<s.size(); i++){
            int d = s[i] - '0';
            sum += d;
            pr *= d;
        }
        int a = sum+pr;
        if(n%a == 0){
            return true;
        }
        return false;
    }
};