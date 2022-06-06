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
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int lh=LH(root);
        int rh=RH(root);
        
        if(lh==rh)
            return (1<<rh)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
        }
    
    int LH(TreeNode* node){
        int counter=0;
        while(node!=NULL){
            counter++;
            node=node->left;
        }
        
        return counter;
    }
    int RH(TreeNode* node){
         int counter=0;
        while(node!=NULL){
            counter++;
            node=node->right;
        }
        
        return counter;
    }
};