// problem link : https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
/*
  hint : work on pick and not pick condition of subsequence problem of recursion condition.

*/  
int subsequence(int ind , vector<int> &arr) {
    if (ind == 0) return arr[ind];
    if (ind < 0) return 0;

    int pick = arr[ind] + subsequence(ind - 2, arr);
    int not_pick = 0 + subsequence(ind - 1, arr);

    return max(pick, not_pick);
}


int main () {

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << subsequence(n-1, arr);
  
  return 0;
}
