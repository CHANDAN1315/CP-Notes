//problem link : https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/


// ***Interview problem vvi**






#include<bits/stdc++.h>
using namespace std;

// Function to find the kth smallest array element
int kthSmallest(int arr[], int n, int k) {

	// For finding min element we need (Max heap)priority queue
	priority_queue<int> pq;
  
  for(int i =0; i<k; i++) pq.push(arr[i]);
  
  for(int i =0; i<n; i++){
    if(arr[i] < pq.top()){
      pq.pop();
      pq.push(arr[i]);
    }
  }
  
 	// Return top of element
	return pq.top();
}


// Driver's code:
int main()
{
	int n = 10;
	int arr[n] = {10, 5, 4 , 3 ,48, 6 , 2 , 33, 53, 10};
	int k = 4;
	cout<< "Kth Smallest Element is: "<<kthSmallest(arr, n, k);

}
