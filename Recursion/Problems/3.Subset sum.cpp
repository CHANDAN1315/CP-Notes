// problem link : https://practice.geeksforgeeks.org/problems/subset-sums2234/1
//TC - 2^n
void solve(vector<int> &a , vector<int> ds, int i) {
    int sum = 0;
    if (i == a.size()) {
        for (auto i : ds) sum += i;
        cout << sum<<" "; return;
    }

    solve(a, ds, i + 1);

    ds.pb(a[i]);
    solve(a, ds, i + 1);


}

int main(){
         int n; cin >> n;
        vector<int> arr(n), ds;
        for (auto &i : arr ) cin >> i;
        sort(all(arr),greater<int>());
        solve(arr, ds, 0);
        cout << endl;
        return 0;
}
