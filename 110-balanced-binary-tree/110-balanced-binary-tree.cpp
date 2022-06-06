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
    bool isBalanced(TreeNode* root) {
        
        int ans=Func(root);
        if(ans==-1)
            return false;
        return true;
        
    }
    
    int Func(TreeNode* &root){  // function to find height of tree, if tree balanced return height else return -1
        
        if(root==NULL)
            return 0;
        int lh=Func(root->left);
        int rh=Func(root->right);
        
    // check for balanced
            if(lh==-1 || rh==-1)
                return -1;
            if(abs(lh-rh)>1)
                return -1;
            
        return 1+max(lh,rh);  // returns height    
    }
};