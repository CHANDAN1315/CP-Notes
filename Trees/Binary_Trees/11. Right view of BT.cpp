// Problem link : https://leetcode.com/problems/binary-tree-right-side-view/
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
// n = number of nodes
// TC : O(n)   SC: O(largest level)

// Simillerly can be solved left view case is i = 0 push elem to ans
// Method 1: Using level order traversal 
class Solution {
public:
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root== NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i =0; i<sz; i++){
                TreeNode* node = q.front();
                q.pop();
                if(i == sz-1) ans.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
        
    }

};


// Using reverse preorder traversal i.e Root-right- left
// TC : O(n)   SC : O(height of BT)
class Solution {
public:
    
    void view(TreeNode* root, int level, vector<int>& ans){
        
        if(root == NULL) return;
        
        if(level == ans.size()) ans.push_back(root->val);
        cout <<level<<" ";
        if(root->right) view(root->right, level+1, ans);
        if(root->left) view(root->left, level+1, ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        // Recursive method
        // reverse preorder traversal - root rig lef
        vector<int> ans;
        if(root == NULL) return ans;
        
        ans.push_back(root->val);
        if(root->right) view(root->right, 1, ans);
        if(root->left) view(root->left, 1, ans);
        return ans;
    }

};
