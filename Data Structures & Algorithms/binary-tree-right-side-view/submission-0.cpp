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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* value = q.front();
            q.pop();

            if(value == NULL){
                ans.push_back(temp[temp.size()-1]);
                temp.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                temp.push_back(value->val);

                if(value->left){
                    q.push(value->left);
                }
                if(value->right){
                    q.push(value->right);
                }
            }
        }
        return ans;
    }
};
