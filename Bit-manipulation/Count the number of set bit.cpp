// problems (basics)
// 1. Count the number of set bits in n.
// code :
// TC - log2(n)

void solve() {
    int n; cin >> n;
    int i = 0;
    int ans = 0;
    while ( n > 0) {
        if ((n & (1 << i)) == 1) ans++;
        n = n >> 1; // if n= 1010 then n = n>>1 -> 101
    }
    cout << ans;
}

/*
    method 2.
    to understand take any two numbers and dry run
    eg : n - 10
        n-1 =  9 (n) & (n-1) = 1010 & 1001 = 1000 (8) the right most bit get removed 

*/
void solve() {
    int n ; cin >> n;
    int cnt = 0;
    while (n > 0) {
        n = (n & (n - 1)); // this is used to remove the rightmost set bit of a number
        cnt++;
    }
    cout << cnt;
}
