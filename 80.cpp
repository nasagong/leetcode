class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int CountOfNum = 1;
        int currentVal = -10001;
        int k = 0;

        for(int num : nums){
            if(currentVal != num){
                currentVal = num;
                CountOfNum = 1;
                nums[k++] = num;
            } else if(currentVal == num){
                if(CountOfNum == 2) continue;
                else{
                    CountOfNum++;
                    nums[k++] = num;
                }
            }
        }

        return k;
    }
};