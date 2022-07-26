// link : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Dynamic sliding window
        int i =0, res =0, cnt =1;
        for(int j =0; j < nums.size(); ++j){
            
            if(nums[j] == 0) cnt--;
            
            while(cnt < 0){
                if(nums[i] == 0) cnt++;
                i++;
            }
            
            res = max(res, j-i);
        }
        return res;
    }
};
