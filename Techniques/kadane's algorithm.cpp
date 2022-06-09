// problem link : https://www.geeksforgeeks.org/maximum-subarray-sum-using-divide-and-conquer-algorithm/
/*
problem : maximum subarray sum 

3 solution discuss 
1. Generating all the subarrays/substrings and finding the max one O(N^3)
2.nerating all the subarrays/substrings and finding the max one O(N^2
3.Kadane's Algo.


*/


void solve() {

    int n ; cin >> n;
    vector<int> a(n);
    read(a);
    int maxx = 0;
    int leng = 1;
    
// Method 1.
    for (int leng = 1; leng <= n; leng++) {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < leng; j++) {
                sum += a[j];
                maxx = max(maxx, sum);
            }
        }
    }

// Method 2.
    for (int i = 0; i < n; i++) {
        int sum = 0;
        if (a[i] > 0) {
            sum += a[i];
            for (int j = i + 1; j < n; j++) {
                // in this part we are doing extra itterations for the same included elements with smaller length.
                if (a[j] < 0) break;
                else sum += a[j];
                maxx = max(sum , maxx);
            }
        }
    }

// Method 3. kadane's algrothium

    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans = max(ans, sum);
        if (a[i] < 0) {
            sum = 0;
        }
    }

    cout << ans;

}
