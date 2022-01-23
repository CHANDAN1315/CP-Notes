
/* Recursion L1  */

/*
    Recursion :- When a function call itself until a specified condition is met.
    Stack overflow :- When memory get full by calling the function again and again and it go beyond 
                        the memory allocated to that call stack then stack overflow happen.


*/

// structure of a recursive code
// int cnt =0;  we can use the global int as well as passed by value int and then call the func() again                   
void func(int &cnt){ // use of reference is good practice , it also work without it unless you make 
                        // changes after the func() call       

    if(cnt == 100) return;    /* when base case is called then the function start returning the values
                                 that we written as (cout <<cnt )-> this will get printed when all func
                                 call gets executed then we get out form our intial func() which we enter
                                 inside the int main(). */
                                /* note:-
                                         until we calling the function our data is stored in stack after
                                         that when the function calls are over then it start executed and 
                                         and we are able to see our output not befor that.       
                                */
    cout <<cnt;
    cnt++;
    func(cnt);  // the func() is calling itself with the value which is incremente by one 
}

int main(){
    int cnt =0;
    func(cnt);

    return 0;
}

// TO read more about recursion :- https://www.geeksforgeeks.org/recursion/#:~:text=A%20recursive%20function%20calls%20itself,created%20for%20each%20function%20call.
