// link : https://leetcode.com/problems/interval-list-intersections/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        while(i < A.size() and j < B.size()){
            int first = max(A[i][0], B[j][0]);
            int second = min(A[i][1], B[j][1]);
            
            if(first <= second) res.push_back(vector<int>{first, second});
            
            if(A[i][1] < B[j][1]) i++;
            else j++;
        }
        return res;
    }
};
