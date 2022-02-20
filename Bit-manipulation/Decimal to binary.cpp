
void solve() {
    int n ; cin >>n;
    string s ="" ; // string will store the binary number.
    while(n > 0){
        int rem = n%2;
        n = n/2;
        s += to_string(rem);
    }
    cout <<s;
}
int main(){
  solve();
  return 0;
}
