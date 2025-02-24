class Solution {
    private:
        unordered_map<int, int> inorderMap;
        int preorderIndex = 0;
    
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }
    
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
    
        int inorderIndex = inorderMap[rootVal];
    
        root->left = buildTreeHelper(preorder, inorder, left, inorderIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, inorderIndex + 1, right);
    
        return root;
    }
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            inorderMap.clear();
            preorderIndex = 0;
    
            for (int i = 0; i < inorder.size(); i++) {
                inorderMap[inorder[i]] = i;
            }
    
            return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1);
        }
    };