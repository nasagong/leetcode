// first solution
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 2){
            return *max_element(nums.begin(), nums.end());
        }
        vector<int> dp(nums.size());

        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);

        for(int i=2; i<nums.size(); i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]); 
        }

        return dp.back();
    }
};

// optimized solution
// space O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 2){
            return *max_element(nums.begin(), nums.end());
        }

        int prev2 = nums[0];
        int prev1 = max(prev2, nums[1]);

        for(int i=2; i<nums.size(); i++){
            int curr = max(prev2+nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};