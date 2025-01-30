class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int max = 987654321;
        if(amount == 0) return 0;
        
        vector<int> dp(amount+1, max);
        for(int value : coins) {
            if(value <= amount) dp[value] = 1;
        }
        dp[0] = 0;

        for(int value : coins){
            for(int i = value; i<=amount; i++){
                dp[i] = min(dp[i-value] + 1, dp[i]);
            }
        }

        if(dp.back() == max) return -1;
        return dp.back();

    }
};