class Solution {
public:
    int originTarget;
    int cnt = 0;

    void solve(vector<int> nums, int idx, int sum){
        if(idx >= nums.size()){
            if(sum == originTarget){
                cnt++;
            }
            return;
        }

        solve(nums, idx+1, sum - nums[idx]);
        solve(nums, idx+1, sum + nums[idx]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        originTarget = target;
        solve(nums, 0, 0);
        return cnt;
    }
};