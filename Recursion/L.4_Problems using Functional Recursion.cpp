/*Lecture 4*/
/*Problems using Functional Recursion*/

// 1.Reverse the array usig recursion

// This is without recursion
void reverse_array(vector<int> &a) {
    for (int i = 0; i < n/2; i++) {
        swap(a[i],a[n-i-1])
    }
}

// reverse array using recursion
void reverse_array(int lo, int hi, vector<int> &a){
    /*note :- we can also do this using only one variable lo 
              take hi = a.size() - lo -1 .  
    */
    
    if(lo > hi) return;
    
    swap(a[lo],a[hi]);

    reverse_array(lo+1,hi-1,a);

}

int main() {
    int lo = 0, hi = 4;
    vector<int> a = {2,3,4,5,6};
    cout<<"before recursion call\n";
    for(auto i : a){
        cout<<i<<" ";
    }
    cout<<endl;

    reverse_array(lo,hi,a);

    cout<<"after recursion call\n";
    for(auto i : a){
        cout<<i<<" ";
    }

    return 0;
}



/*2. Check the given string is a palindrome or not*/


// Using iterative method
bool is_palo(string &s , int &n) {
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
}

// Using recursive method

// note :-  The data type of the function is very important so chose them carefully
void is_palo(int &lo, string &s , int &n){
// my code i.e is a jugar code but not good one.
    if(lo >= n/2) {
        cout<<1;
        return;
    }
    if(s[lo] == s[n-lo-1]) {
        is_palo(lo+1,s,n);
    }
    else{
        cout<<0;
        return;
    }

}
// striver code
// T.C - n/2 
// S.C - stack space(internal memory) n/2
bool is_palo(int &lo , string &s , int &n){
    if(lo >= n/2) return true;

    if(s[lo] != s[n-lo-1]) return false;

    return is_palo(lo+1,s,n); /* in this return store the the function inside the stack memory
                                so that after the recursion call are over then it will return 
                                some value that are store in the stack
                            */
}
int main(){
    int n ; cin>>n;
    string s ; cin >>s;
    cout<<is_palo(0,s,n)
}
