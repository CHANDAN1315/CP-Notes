 /* Phoenix_15 (Chandan Kumar) */
// problem link : https://leetcode.com/problems/palindrome-partitioning/

/* Approch : 
           In this problem we use horizontal recursion calls and inside one recursion call there are two recursion calls 
*/

#include<bits/stdc++.h>
using namespace std;

typedef long double lld;
typedef unsigned long long ull;
const int mod = 1000000007;
const int mini = -2147483648;
const int maxi =2147483647;
#define int long long int
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pb emplace_back
#define pop pop_back()
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
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
int binaryToDecimal(string n){string num = n;int dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


bool is_palindrome(string s,int start, int end) {
    
    while(start <= end){
        if(s[start++] != s[end--]) return false;
    }
    return true;
}

void solve(int ind, string s , vector<string> &path, vector<vector<string>> &ans) {

    if(ind == s.size()){
        ans.pb(path);
        return;
    }
    for(int i =ind; i< s.size(); i++){
        if(is_palindrome(s,ind,i)){
            path.pb(s.substr(ind,i-ind+1));
            solve(i+1,s,path,ans);
            path.pop_back();
        }
    }

    
}
 
signed main() {

    int t = 1;
    //cin >> t;
    while (t--) {
        vector<vector<string>> ans;
        vector<string> path;
        string s; cin >>s;
        solve(0,s,path,ans);
        for(auto i : ans){
            for(auto j : i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        // cout << endl;
    }

}
