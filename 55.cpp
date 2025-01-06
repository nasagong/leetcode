class Solution {

public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int maxReachableIdx = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(i > maxReachableIdx) return false;

            maxReachableIdx = max(maxReachableIdx, i+nums[i]);

            if(maxReachableIdx >= nums.size()-1) return true;
        }

        return false;
    }
};s