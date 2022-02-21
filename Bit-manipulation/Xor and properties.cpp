// # Xor and its properties

// 1. a^a = 0
// 2. 0^a = a
// 3. ordering in xor doest matter

//         2^3^1 == 3^1^2

// q1. Compute XOR from 1 to n (direct method) :
// soln.
int computeXOR(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

// q2. Total sum of xor pairs

// n^2 soln
void sove() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            res += a[i] ^ a[j];
        }
    }
}

// approch : In this we will count the number of set bits and unset bits at the i'th position

// if no. of set bit at ith pos is = x
//     no. unset bit of ith pos is = y
//     no. of pairs that can form at ith bit = xy

//     contrubution of that ith bit is  (2^bitpos * xy)

// nlogn soln
void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (auto &i : a) cin >> i;
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int cnt1 = 0, cnt0 = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j] & (1 << i)) cnt0++;
            else cnt1++;
        }
        int pairs = cnt1 * cnt0;
        ans += (1 << i) * pairs;
    }
    cout << ans;
}
