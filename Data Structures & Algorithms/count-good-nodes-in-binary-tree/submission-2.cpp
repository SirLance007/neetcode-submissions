class Solution {
private:
    void solve(TreeNode* root , int &count, int value){
        if(root == NULL){
            return;
        }
        if(value <= root->val){
            count++;
            value = root->val;
        }
        solve(root->left , count , value);
        solve(root->right , count , value);
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        solve(root , count , root->val);
        return count;
    }
};