class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int maxsum = 0;

        for (int i = 0; i<k; i++){
            lsum += cardPoints[i];
        }
        maxsum = lsum;

        int ri = cardPoints.size() - 1;
        for(int i = k-1; i>=0; i--){
            rsum += cardPoints[ri];
            lsum -= cardPoints[i];
            ri--;
            maxsum = max(maxsum, lsum+rsum);
        }

        return maxsum;
    }
};