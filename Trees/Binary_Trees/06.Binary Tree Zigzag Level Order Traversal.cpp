// Problem : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/

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
// Imp 1.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool f =0;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
                
            if(f) reverse(level.begin(), level.end());
            f = !f;
            ans.push_back(level);
        }
        return ans;
    }
};



// Imp2.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight =0;
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            
            for(int i=0; i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                // find position to fill the node.
                int ind = (leftToRight ? i : size-1-i);
                level[ind] = node->val;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);

            }
            // After the level.
            leftToRight = !leftToRight;
            ans.push_back(level);
        }
      
    }
};
