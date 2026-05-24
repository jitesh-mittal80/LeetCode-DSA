class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m*k > n){
            return -1;
        }

        int ans;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low<=high){
            int mid = low + (high - low)/2;
            int count = 0;
            int b = 0;

            for (int i = 0; i<n; i++) {
                if (bloomDay[i] <= mid){
                    count++;
                }

                else{
                    b = b + count/k;
                    count = 0;
                }

            }
            b = b + count/k;
            if (b>=m){
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