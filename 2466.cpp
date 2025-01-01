class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(high+1, 0LL);
        dp[0] = 1;
        int ans = 0;

        // unitil high
        // return sum of dp[low] to dp[high]

        for(int i=1; i<=high; i++){
            if(i-zero >= 0){
                dp[i] = (dp[i] + dp[i-zero]) % MOD;
            }
            if(i-one >= 0){
                dp[i] = (dp[i] + dp[i-one]) % MOD;
            }
        }

        for(int i=low; i<=high; i++){
            ans = (ans+dp[i]) % MOD;
        }
    
        return static_cast<int>(ans);
    }
};