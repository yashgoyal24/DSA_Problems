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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         if(postorder.size()==1){
            // single node which will be root itself
            TreeNode* root= new TreeNode(postorder[0]);
            return root;
        }
        
        // store index of inorder elements in a map
        
        map<int, int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        
        
        
        return F(postorder, inorder, 0, inorder.size()-1,0,postorder.size()-1,mp);
    }
    
    
      TreeNode* F(vector<int>& postorder, vector<int>& inorder,int inStart, int inEnd, int postStart, int postEnd, map<int,int> &mp){
          
        if(inStart>inEnd || postStart>postEnd){
            // no nodes left
            return NULL;
        }
       // else{
         
             TreeNode* root=new TreeNode(postorder[postEnd]);
            // call for left subtree
            
            int leftNodes=mp[postorder[postEnd]] - inStart;
            root->left=F(postorder, inorder, inStart, mp[postorder[postEnd]]-1, postStart,postStart+leftNodes-1 ,mp);
            
            // call for right subtree
            
            root->right=F(postorder, inorder,mp[postorder[postEnd]]+1, inEnd,postStart+leftNodes , postEnd-1,mp);
     //   }
        return root;
    }
};