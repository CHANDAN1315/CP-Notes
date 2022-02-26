/*problem link : https://leetcode.com/problems/permutations/*/

class Solution {
private: 
    void recurepermute(vector<int> &ds,vector<int> &nums,vector<vector<int>> &ans,int freq[]){
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurepermute(ds,nums,ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }

        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i =0; i< nums.size(); i++) freq[i] = 0;
        recurepermute(ds,nums,ans,freq);
        return ans;
        
    }
};

// approch 2 : Without extra space of frequency count

void solve(vector<int> a, int ind) {

    if (ind == a.size()) {
        for (auto i : a) cout << i << " ";
        cout << endl;
        return;
    }

    for (int i = ind; i < a.size(); i++) {
        swap(a[ind], a[i]);
        solve(a, ind + 1);
    }

}
