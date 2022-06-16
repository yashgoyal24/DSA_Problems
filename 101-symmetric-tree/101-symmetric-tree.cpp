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
    bool isSymmetric(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            // root has no children
            return true;
        }
        
        else return F(root->left, root->right);
  
    }
    
    bool F(TreeNode* left, TreeNode* right){
        
        
        if(left==NULL || right==NULL){
            return (left==right);
        }
        if(left->val!=right->val)
            return false;
       
        bool bool_left=F(left->left,right->right);
        bool bool_right=F(left->right,right->left);
        return ((left->val==right->val) && bool_left && bool_right);
    }
};