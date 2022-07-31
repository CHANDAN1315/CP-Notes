// Link : https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ds(26,-1);
        for(int i =0; i<s.size(); i++){
            ds[s[i] - 'a'] = i;
        }
        
        vector<int> res;
        int pre = -1;
        int maxx = 0;
        
        for(int i =0; i<s.size(); i++){
            maxx = max(ds[s[i] -'a'], maxx);
            if(maxx == i){
                res.push_back(maxx - pre);
                pre = maxx;
            }
        }
        return res;
    }
};
