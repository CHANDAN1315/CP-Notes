//Problem link:
//https://www.codingninjas.com/codestudio/problems/bottom-view-of-binary-tree_893110?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos

vector<int> bottomView(TreeNode<int> * root){
 
    map<int, int> mp; // Note : we use map to get the order left to right 
    vector<int> ans;
    queue<pair<TreeNode<int>*, int>> q;
    
    if(root == NULL) return ans;
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        auto node = p.first;
        int x = p.second;
        mp[x] = node->val;
        if(node->left) q.push({node->left, x-1});
        if(node->right) q.push({node->right, x+1});
 
    }
     for(auto i : mp){
         ans.push_back(i.second);
     }   
    return ans;
     
}
