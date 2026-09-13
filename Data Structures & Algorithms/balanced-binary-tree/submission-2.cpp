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
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = solve(root->left)+1;
        int right = solve(root->right)+1;
        int maxi = max(right , left);
        return maxi;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int lefty = solve(root->left)+1;
        int righty = solve(root->right)+1;
        if(abs(lefty-righty) > 1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
