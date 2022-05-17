int upper_bound(int low, int high , vector<int> &arr){
int low =0, high = n-1;
while (low < high) {
        // Find the middle index
        mid = low + (high - low) / 2;
 
        // If X is greater than or equal
        // to arr[mid] then find
        // in right subarray
        if (X >= arr[mid]) {
            low = mid + 1;
        }
 
        // If X is less than arr[mid]
        // then find in left subarray
        else {
            high = mid;
        }
    }
   
    // if X is greater than arr[n-1]
    if(low < N && arr[low] <= X) {
       low++;
    }
    return low;
}
