class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for (int i = 0; i<weights.size(); i++){
            high = high + weights[i];
        }
        int ans = -1;

        while (low <= high){
            int mid = low + (high - low)/2;
            int d = 1;
            int w = 0;

            for (int i = 0; i<weights.size(); i++){
                if (weights[i] + w > mid){
                    d++;
                    w = weights[i];
                }

                else{
                    w = w+ weights[i];
                }
            }

            if (d<=days){
                ans = mid;
                high = mid - 1;
            }

            else{
                low = mid+1;
            }
        }
        return ans;
    }
};