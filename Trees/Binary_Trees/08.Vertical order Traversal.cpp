//Problem link :https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Revise angain and again vvi concept


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

// TC : O(N*logN) logN for multiset     SC: O(N)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;
        
        q.push({root,{0,0}});
        while(!q.empty()){
            int sz = q.size();
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->val);
            
            if(node->left) q.push({node->left, {x-1, y+1}});
            if(node->right) q.push({node->right, {x+1, y+1}});
            
        }

        vector<vector<int>> ans;
        for(auto i : nodes){
            vector<int> tmp;
            for(auto j : i.second){
               tmp.insert(tmp.end(), j.second.begin(), j.second.end()) ;
            }
            ans.push_back(tmp);
        }
        return ans;
        

        
    }
};
