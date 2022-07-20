// Problem link : https://leetcode.com/problems/maximum-score-of-spliced-array/

class Solution {
public:
  // Using kadanes algorithum
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
        int sum1 =0 ,sum2 =0, ans =0;
        for(auto i : nums1) sum1 += i;
        for(auto i : nums2) sum2 += i;
        
        ans = max(sum1, sum2);
        
        int maxSum =0;
        int cur =0;
        for(int i =0; i<nums1.size(); i++){
            cur += nums2[i] -nums1[i];
            maxSum = max(cur, maxSum);
            if(cur < 0) cur =0;
        }
        ans = max(ans, maxSum + sum1);
        
        maxSum =0;
        cur =0;
        
        for(int i =0; i<nums1.size(); i++){
            cur += nums1[i] -nums2[i];
            maxSum = max(cur, maxSum);
            if(cur < 0) cur =0;
        }
         ans = max(ans, maxSum + sum2);
        
        return ans;
   
        
    }
};

// My method to solve (bad one)
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
              int sum1 = 0, sum2 = 0;
        int n = nums1.size();
        for(int i =0; i<nums1.size(); i++){
            sum1+= nums1[i];
            sum2 += nums2[i];
        }
        vector<int> s1(n) ,s2(n) ;
        int maxpre2 = 0;
        int maxpre1 = 0;
        // case1
        for(int i =0; i<n; i++){
            s2[i] = nums2[i] - nums1[i]; 
        }

        int premx = 0;
        for(int i =0; i<s2.size(); i++){
            if(s2[i] + premx > 0){
                premx+= s2[i];
                maxpre2 = max(premx, maxpre2);
            }
            
            else {
                premx = 0;
            }
        }
        
        int ans1 = sum1+ maxpre2;
        // transfer from ar2 -> ar1
        
        // case2
        for(int i =0; i<n; i++){
            s1[i] = nums1[i] - nums2[i]; 
        }

        premx = 0;
        for(int i =0; i<s1.size(); i++){
            if(s1[i] + premx > 0){
                premx+= s1[i];
                maxpre1 = max(premx, maxpre1);
            }
            else {
                premx = 0;
            }
        }
        
        int ans2 = sum2+ maxpre1;
        cout <<maxpre1<<" "<<maxpre2<<endl;
        cout <<ans1<<ans2;
        return max(ans1, ans2);
    }
};
