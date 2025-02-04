class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        //dp[i] => the legnth of longest subsequnce that last number is nums[i]
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// greedy
int lengthOfLIS(vector<int>& nums) {
    vector<int> lis;

    for (int num : nums) {
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if (it == lis.end()) {
            lis.push_back(num);
        } else {
            *it = num; 
        }
    }

    return lis.size();
}