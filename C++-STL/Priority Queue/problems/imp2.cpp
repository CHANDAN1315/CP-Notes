// Problem : https://leetcode.com/problems/k-closest-points-to-origin/
// MY imp : 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i =0; i<points.size(); i++){
            int k = points[i][0]*points[i][0] + points[i][1]*points[i][1] ;
            // cout <<k<<" ";
            pq.push({k , i});
        }
        vector<vector<int>> ans;        
        while(k > 0 and !pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            vector<int> a = points[p.second];
            ans.push_back(a);
            k--;
        }
        return ans;
    }
};

// Wonderfull imp by making max heap and inserting -ve value to make it min heap
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> heap;
        vector<vector<int>> send;
        
        for(int i=0;i<points.size();i++){
            int distance=pow(points[i][0],2)+pow(points[i][1],2);
            heap.push({-distance,i});
        }
        
        for(int i=0;i<k;i++){
            send.push_back(points[heap.top().second]);
            heap.pop();
        }
        
        return send;
    }
};
