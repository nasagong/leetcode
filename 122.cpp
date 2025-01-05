class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int minPrices = prices[0];
        int maxProfit = 0;

        for(int i=1; i<prices.size(); i++){
            if(prices[i] < minPrices){
                minPrices = prices[i];
            } else{
                maxProfit = max(maxProfit, prices[i] - minPrices);
            }
        }

        return maxProfit;
    }
};