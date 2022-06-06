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
    bool findTarget(TreeNode* root, int k) {
        
        Inorder(root);
        
        // now apply 2 sum to "inorder" array which is sorted
        
        int i=0,j=inorder.size()-1;
        
        while(i<j){
            
            if(inorder[i]+inorder[j]==k)
            return true;
             else if(inorder[i]+inorder[j]<k)
        i++;
        else
            j--;
        }
       
        return false;
        
    }
    
    void Inorder(TreeNode* &root){
        
        if(root==NULL)
            return;
        
        Inorder(root->left);
        inorder.push_back(root->val);
        Inorder(root->right);
            
        
    }
    
    
    
};