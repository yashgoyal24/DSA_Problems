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
vector<int> preorder;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        Preorder(root);
        return preorder;
    }
    
      
    void Preorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        
      
        Preorder(root->left);
        Preorder(root->right);
          preorder.push_back(root->val);
    }
};