class Solution {
    bool solve(TreeNode* root , TreeNode* subRoot){
        if(root == NULL && subRoot == NULL){
            return true;
        }
        if(root == NULL || subRoot == NULL){
            return false;
        }
        if(root->val != subRoot->val){
            return false;
        }
        bool lefty = solve(root->left , subRoot->left);
        bool righty = solve(root->right , subRoot->right);
        return lefty && righty;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL){
            return false;
        }
        if(subRoot == NULL){
            return true;
        }

        if(root->val == subRoot->val && solve(root , subRoot)){
            return true;
        }

        bool lefty = isSubtree(root->left , subRoot);
        bool righty = isSubtree(root->right , subRoot);
        return lefty || righty;
    }
};
