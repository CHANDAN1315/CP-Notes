// Brute solution 
/*
  find all the permutation and then print the next permutation.
*/ 


// optimal solution

/*some time ther are problems which requires to travel from back side manuplate the array.


*/ 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = 0;
        bool f =0;
        for(int i =n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                f =1;
                break;
            }
        }
        int ind2 =0;
        for(int i =n-1; i>ind; i--){
            if(nums[i] > nums[ind]){
                ind2 = i;
                break;
            }
        }
        if(f){
            swap(nums[ind],nums[ind2]);
            sort(nums.begin()+ind+1, nums.end());
        }
        else {
            sort(nums.begin(),nums.end());
        }
        
        // Same solution with better implementation.
        
        int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
        
        
    }
};
