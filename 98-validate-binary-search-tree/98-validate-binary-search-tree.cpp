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
vector<int> inorder;
    bool isValidBST(TreeNode* root) {
        
        Inorder(root);
        vector<int> copy=inorder;
        sort(inorder.begin(),inorder.end());
        for(int i=0;i<copy.size()-1;i++){
            if(inorder[i]==inorder[i+1])
                return false;
            if(inorder[i]!=copy[i])
                return false;
                
        }
        
        if(copy[copy.size()-1]!=inorder[copy.size()-1])
            return false;
        
        return true;
    }
    
    void Inorder(TreeNode* &root){
        
        if(root==NULL)
            return;
        
        Inorder(root->left);
        inorder.push_back(root->val);
        Inorder(root->right);
    }
};