//link : https://leetcode.com/problems/max-consecutive-ones-iii/
/*
  Approch : using two pointer and sliding window technique
  important concept to rember
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lo =0, hi =0;
        int res =0;
        int ans = -1;
        while(hi < nums.size()){
            if(nums[hi] == 1){
                res++;
                hi++;
            } 
            else if(nums[hi] == 0 and k > 0){
                res++;
                k--;
                hi++;
            }
            else {
                if(nums[lo] == 0) k++;
                lo++;
                res--;
            }
            ans = max(ans, res);
        }
        return ans;
    }
};
