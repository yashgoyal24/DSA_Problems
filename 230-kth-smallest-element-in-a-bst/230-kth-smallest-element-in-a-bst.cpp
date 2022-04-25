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
    
vector<int> ds;
public:
    int kthSmallest(TreeNode* root, int k) {
        in_order(root);
        
        return ds[k-1];
    }
    
   void in_order(TreeNode* &root){
        
        if(root==NULL)
            return;
        
        in_order(root->left);
     
        ds.push_back(root->val);
        
        in_order(root->right);
       
        
    }
};