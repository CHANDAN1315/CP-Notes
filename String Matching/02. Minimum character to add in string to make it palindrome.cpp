//link : https://practice.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/
class solution{
  public:
  vector<int> LPS(string str){
        int n = str.size();
        vector<int> lps(n);
        
        int len =0, i =1;
        while(i<n){
            if(str[i] == str[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if(len != 0) len = lps[len-1];
                else{
                    lps[i] =0;
                    i++;
                }
            }
        }
        return lps;
    }
};
    
int minChar(string str){
      string rev = str;
      reverse(rev.begin(), rev.end());
      int n = str.size();
      string concat = str+'$'+rev;
      // cout<<concat;
      vector<int> lps = LPS(concat);
      int m= lps.size()-1;

      // for(auto i : lps) cout <<i<<" ";
      return n-lps[m];
}
