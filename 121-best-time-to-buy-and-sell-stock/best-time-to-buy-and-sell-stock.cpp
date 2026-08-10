class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int maxprofit = 0;
        for(int i = 1; i<prices.size(); i++){
            if(buy > prices[i]){
                buy = prices[i];
            }

            int profit = prices[i] - buy;
            maxprofit = max(profit, maxprofit);
        }

        return maxprofit;
    }
};