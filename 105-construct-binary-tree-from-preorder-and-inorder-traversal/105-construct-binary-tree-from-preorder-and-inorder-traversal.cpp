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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size()==1){
            // single node which will be root itself
            TreeNode* root= new TreeNode(preorder[0]);
            return root;
        }
        
        // store index of inorder elements in a map
        
        map<int, int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        
        
        
        return F(preorder, inorder, 0, inorder.size()-1,0,preorder.size()-1,mp);
    }
    
    TreeNode* F(vector<int>& preorder, vector<int>& inorder,int inStart, int inEnd, int preStart, int preEnd, map<int,int> &mp){
          
        if(inStart>inEnd || preStart>preEnd){
            // no nodes left
            return NULL;
        }
       // else{
         
             TreeNode* root=new TreeNode(preorder[preStart]);
            // call for left subtree
            
            int leftNodes=mp[preorder[preStart]] - inStart;
            root->left=F(preorder, inorder, inStart, mp[preorder[preStart]]-1, preStart+1,preStart+leftNodes ,mp);
            
            // call for right subtree
            
            root->right=F(preorder, inorder,mp[preorder[preStart]]+1, inEnd,preStart+leftNodes+1 , preEnd,mp);
     //   }
        return root;
    }
};