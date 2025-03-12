/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
    private:
        int traverse(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long,int>& sumMap){
            if(node == nullptr) return 0;
    
            currentSum += node->val;
            int pathCount = 0;
    
            if(sumMap.find(currentSum - targetSum) != sumMap.end()) {
                pathCount += sumMap[currentSum - targetSum];
            }
    
            sumMap[currentSum]++;
    
            pathCount += traverse(node->left, currentSum, targetSum, sumMap);
            pathCount += traverse(node->right, currentSum, targetSum, sumMap);
    
            sumMap[currentSum]--;
    
            return pathCount;
        }
    
    public:
        int pathSum(TreeNode* root, int targetSum) {
            unordered_map<long long,int> sumMap;
            sumMap[0] = 1;
            return traverse(root, 0, targetSum, sumMap);
        }
    };