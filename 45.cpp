class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i=0; i<n-1; i++){
            for(int jump=1; jump<=nums[i]; jump++){
                if(i+jump >= n) break;
                dp[i+jump] = min(dp[i+jump], dp[i]+1);
            }
        }

        return dp[n-1];
    }
};