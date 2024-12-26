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
public:
    int cnt = 0;

    void countSwap(vector<int> v){
        for(int i=0; i<v.size()-1; i++){
            int minIdx = i;

            for(int j=i+1; j < v.size(); j++){
                if(v[j] < v[minIdx]){
                    minIdx = j;
                }
            }

            if(minIdx != i){
                swap(v[i], v[minIdx]);
                cnt++;
            }
        }
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int qz=q.size();
            vector<int> arr(qz,0);
            for(int i=0; i<qz; i++){
                auto node = q.front();
                q.pop();
                arr[i] = node -> val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            countSwap(arr);
        }
        return cnt;
    }
};