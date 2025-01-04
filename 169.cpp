class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hm;

        int currentCnt = 1;
        int max = -1;
        int ans;

        if(nums.size() == 1){
            return nums[0];
        }
        
        sort(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
                hm[nums[i-1]] = currentCnt;
                currentCnt = 1;
            } else {
                hm[nums[i]] = ++currentCnt;
            }
        }

        for(const auto& pair : hm){
            if(pair.second > max){
                max = pair.second;
                ans = pair.first;
            }
        }

        return ans;
    }
};