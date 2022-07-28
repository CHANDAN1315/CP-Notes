class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        // first count the number of elemets that are greater , less , equal to p using three pointer
      // Better  
      int n = nums.size();
        int point = 0;
        vector<int> res(n);
        for(auto i : nums){
            if(i < pivot) res[point++] = i;
        }
        for(auto i : nums){
            if(i == pivot) res[point++] = i;
        }
        for(auto i : nums){
            if(i > pivot) res[point++] = i;
        }
        return res;
        
        // Brute
        // vector<vector<int>> vec(3);
        //  for(auto i : nums){
        //     if(i > pivot){
        //         vec[2].push_back(i);
        //     }
        //     else if(i < pivot){
        //         vec[0].push_back(i);
        //     }
        //     else {
        //         vec[1].push_back(i);
        //     }
        // }
        // vector<int> ans;
        // for(auto i : vec){
        //     for(auto j : i){
        //         ans.push_back(j);
        //     }
        // }
        // return ans;
    }
};
