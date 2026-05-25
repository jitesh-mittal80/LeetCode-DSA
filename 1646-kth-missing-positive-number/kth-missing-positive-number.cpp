class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int> s(arr.begin(), arr.end());

        int count = 0;
        int num = 1;

        while(true){
            if (s.find(num) == s.end()){
                count++;

                if (count == k){
                    return num;
                }
            }

            num++;
        }
    }
};