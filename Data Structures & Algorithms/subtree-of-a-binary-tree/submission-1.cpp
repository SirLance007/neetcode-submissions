class Solution {
private:
    void subtree(TreeNode* root, TreeNode* subRoot, bool &isTrue) {
        if (!root && !subRoot) {
            return;
        }
        if (!root || !subRoot) {
            isTrue = false;
            return;
        }
        if (root->val != subRoot->val) {
            isTrue = false;
            return;
        }
        if (!isTrue) return; // Stop further recursion if already false
        subtree(root->left, subRoot->left, isTrue);
        if (!isTrue) return; // Stop further recursion if already false
        subtree(root->right, subRoot->right, isTrue);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false; // Handle edge case when root is null
        
        if (root->val == subRoot->val) {
            bool isTrue = true;
            subtree(root, subRoot, isTrue);
            if (isTrue) {
                return true;
            }
        }

        // Return result of recursive calls instead of ignoring them
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
