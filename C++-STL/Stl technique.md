1. Left rotate the array by k units.

        // n - size() of vector , k - length up to which array need to rotated.        
        void leftrotate(vector<int> &a, int n , int k){
            k %= n;
            reverse(a.begin(),a.begin()+k);
            reverse(a.begin()+k, a.begin()+n);
            reverse(a.begin(),a.begin()+n);
        }

2.Right rotate the array by k unit.
  
        // n - size() of vector , k - length up to which array need to rotated.        
        void leftrotate(vector<int> &a, int n , int k){
            k %= n;
            reverse(a.begin()+k, a.begin()+n);
            reverse(a.begin(),a.begin()+k);
            reverse(a.begin(),a.begin()+n);
        }
