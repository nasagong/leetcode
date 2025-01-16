class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        vector<int> left_products(n,1);
        vector<int> right_products(n,1);

        int product = 1;
        for(int i=0; i<n; i++){
            left_products[i] = product;
            product *= nums[i];
        }

        product = 1;
        for(int i=n-1; i>=0; i--){
            right_products[i] = product;
            product *= nums[i];
        }

        for(int i=0; i<n; i++){
            answer.push_back(left_products[i]*right_products[i]);
        }

        return answer;
    }
};