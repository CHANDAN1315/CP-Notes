// Problem link : https://www.codingninjas.com/codestudio/problems/time-to-burn-tree_630563?
//                source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos
/*
    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

TC: O(nlogn) + O(n) + O(n)    SC: O(n)

************************************************************/
BinaryTreeNode<int>* makeparent(unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> mpp, BinaryTreeNode<int>* root, int start){
    queue<BinaryTreeNode<int>*> q;
    BinaryTreeNode<int>* res;
    q.push(root);
    while(!q.empty()){
        auto node = q.front();
        if(node->val == start) res = node;
        q.pop();
        if(node->left){
            q.push(node->left);
            mpp[node->left] = node;
        }
        if(node->right){
            q.push(node->right);
            mpp[node->right] = node;
        }
    }
    return res;
}


int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> mpp;
    BinaryTreeNode<int>* targetnode =  markparent(mpp,root,start);   
    
    queue<BinaryTreeNode<int>*> q;
    q.push(targetnode);
    map<BinaryTreeNode<int>*, bool> visited;
    visited[targetnode] = true;
    int res =0;
    while(!q.empty()){
        int sz = q.size();
        bool f = 0;
        for(int i =0; i<sz; i++){
            auto current = q.front();
            q.pop();
            if(current->left and !visited[current->left]){
                f =1;
                q.push(current->left);
                visited[current] = true;
            }
            if(current->right and !visited[current->right]){
                f =1;
                q.push(current->right);
                visited[current] = true;
            }
            if(mpp[current] and !visited[mpp[current]]){
                f =1;
                q.push(mpp[current]);
                visited[mpp[current]] = true;
            }
        }
        if(f) res++;
    }
    return res;
    
}
