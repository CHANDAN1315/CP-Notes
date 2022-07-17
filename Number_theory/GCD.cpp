/* 
When you requried the common divisor of array 
v = {2,4,6,8}
common divisor of whole array  i.e gcd = 2
*/

// Condition : a > b
int GCD(int a , int b){
  if(a == 0) return b;
  else return GCD(b%a, a);
}

void solve(){
    vector<int> v = {2,4,6,8};
    int gcd = v[0];
    for(int i=1; i<v.size(); i++){
        gcd = GCD(gcd, v[i]);
    }
    return gcd;
  }
