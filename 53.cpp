class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currentSum = 0;
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            currentSum = max(nums[i], currentSum + nums[i]);
            ans = max(ans,currentSum);
        }
        return ans;
    }
};