/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // using normal BT logic for calculating LCA
        
        if(root==NULL || root==p || root==q)
            return root;
        
        TreeNode* left_ancestor=lowestCommonAncestor(root->left, p, q);
        TreeNode* right_ancestor=lowestCommonAncestor(root->right, p, q);
        
        if(left_ancestor==NULL && right_ancestor==NULL)
            return NULL;
        
        if(left_ancestor==NULL){
            return right_ancestor;
        }
        else if(right_ancestor==NULL){
            return left_ancestor;
        }
        else{
            // both are not null
            return root;
        }
    }
};