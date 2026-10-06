class Solution {
public:
    int minAddToMakeValid(string s) {
        while (true) {
            size_t pos = s.find("()");

            if (pos == string::npos) {
                return static_cast<int>(s.size());
            }

            s = s.substr(0, pos) + s.substr(pos + 2);
        }
    }
};