/*
problem : find the maximum sum of subarray of size k.

Sol : method1 : using 2 for loops and finding the maximum sum.
method 2 : using sliding window .

*/

// Method 1: TC : O(n^2)


int maxSum(int arr[], int n, int k)
{
    // Initialize result
    int max_sum = INT_MIN;
 
    // Consider all blocks starting with i.
    for (int i = 0; i < n - k + 1; i++) {
        int current_sum = 0;
        for (int j = 0; j < k; j++)
            current_sum = current_sum + arr[i + j];
 
        // Update result if required.
        max_sum = max(current_sum, max_sum);
    }
 
    return max_sum;
}



// Method 2 : Time : O(n) 

int maxSum(int arr[], int n, int k)
{
    // n must be greater
    if (n < k) {
        cout << "Invalid";
        return -1;
    }
 
    int max_sum = 0;
    for (int i = 0; i < k; i++)
        max_sum += arr[i];
  
    int ans = max_sum;
    for (int i = k; i < n; i++) {
         max_sum += arr[i] - arr[i - k];
        ans = max(max_sum, ans);
    }
 
    return ans;
}
