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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> result;
        
        //create an ordered map ds to store the mapping
        
        map<int,map<int,multiset<int>>> mp;  // vertical, level, elements on a particular level(row)
        
        //do a level order traversal to plug in the values
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        q.push({root,{0,0}});
        
        while(!q.empty()){
            
            pair<int,int> p=q.front().second;
            int vertical=p.first;
            int level=p.second;
            TreeNode* node=q.front().first;
                   q.pop();
            mp[vertical][level].insert(node->val);
            
     
            
            if(node->left!=NULL)
                q.push({node->left,{vertical-1,level+1}});
            
            if(node->right!=NULL)
                q.push({node->right,{vertical+1,level+1}});
            
            
        }
        
        //now traverse map and insert in result vector of vector
        
              for (auto p : mp) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            result.push_back(col);
        }
        
        
        
        return result;
    }
};