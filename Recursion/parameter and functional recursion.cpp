/*Recursion L2 and L3 */

/*1.Print the number till n*/
void func(int n){

    if(n < 1) return;
    cout<<n;  // This will print the number when we go inside the other func
    func(n-1);    
    cout<<n;/* This will print from (1 to n ) when we get out from the function 
                and end our prgram. This step is called backtracking.
            */
}


/*Que : Find the sum of first n numbers
  Sol : 
        1. using parameter
        2.functional way  
*/

// using parameter way :-

void SumUpToN(int i , int sum){
    if(i < 1){
        cout<< sum;
        return;
    }

    SumUpToN(i - 1, sum + i);
}


// Using function calls :-
int SumUpToN(int n){

    if(n == 0) return 0;
    
    // cout<< n+SumUpToN(n-1) <<endl;  // This is a check
    return n + SumUpToN(n-1);
}


