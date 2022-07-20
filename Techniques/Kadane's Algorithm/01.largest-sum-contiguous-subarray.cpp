//Problem link : https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

class solution{
  public:
  int maxSubArraySum(int a[], int size)
  {
    int max_so_far = INT_MIN, max_ending_here = 0;
  
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
  
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
  }
};


// Method2  Using DP handle cases when all the elements are -ve
class solution{
  public:
  int maxSubArraySum(int a[], int size)
  {
     int max_so_far = a[0];
     int curr_max = a[0];

     for (int i = 1; i < size; i++)
     {
          curr_max = max(a[i], curr_max+a[i]);
          max_so_far = max(max_so_far, curr_max);
     }
     return max_so_far;
  }
};
