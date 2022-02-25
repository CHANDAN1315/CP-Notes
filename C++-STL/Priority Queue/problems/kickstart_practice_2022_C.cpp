/* Phoenix_15 (Chandan Kumar) */

#include<bits/stdc++.h>
using namespace std;

typedef long double lld;
typedef unsigned long long ull;
const int mod = 1000000007;
const int mini = -2147483648;
const int maxi = 2147483647;
#define pii pair<int, int>
#define int long long int
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pb emplace_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define yes "YES"
#define no "NO"
#define endl "\n"
#define sz(x) x.size()
#define rt return
#define setbit(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define ps(x,y) fixed<<setprecision(y) << x
#define fo(i, a, b) for(int i =(int)a; i<=(int)b; ++i)
#define bfo(i ,a, b) for(int i =(int)a; i>=(int)b; --i)
#define read(a) for(int i =0; i<a.size(); ++i){ cin>>a[i];}
#define cff(a,b) ((a%b) ? a/b + 1 : a/b) //ceil and floor function
#define google(i) cout<<"Case" << " #" << i << ":" << " ";

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(unordered_set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//================================================================================================================================




signed main() {

#ifndef Chandan_Kumar
    freopen("Error.txt", "w", stderr);
#endif

    FIO // input output

    auto start = chrono::high_resolution_clock::now();

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        google(i)
        int n; cin >> n;
        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        int cnt = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i <= n; i++) {
            // this is used to remove the element which get inserted before the updated ans.
            // thats why we are taking minheap pq
            while (!pq.empty() and pq.top() <= ans) {
                pq.pop();
                cnt--;
            }
            if (a[i] > ans) {
                pq.push(a[i]);
                cnt++;
            }
            if (cnt == ans + 1) ans++;

            cout << ans << " ";
        }
        cout << endl;
    }
    // int cnt = 0;
    // for (int j = 1; j <= i; j++) {
    //     if (a[j] > ans) {
    //         cnt++;
    //         ans = max(cnt, ans);
    //          if(cnt == ans+1) ans = cnt; same step like the above step
    //     }
    // }
    // cout << ans << " ";
    // }


    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cerr << endl << "Time : " << duration.count() / 1e3 << " ms\n";
}
