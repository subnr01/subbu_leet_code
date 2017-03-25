
/*

Find the length of the longest subsequence of a given sequence such 
that all elements of the subsequence are sorted in increasing order. 
For example, length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } 
is 6 and LIS is {10, 22, 33, 50, 60, 80}.

*/



/* 
Optimal substructure

Let arr[0..n-1] be the input array and L(i) be the length of the LIS till index i 
such that arr[i] is part of LIS and arr[i] is the last element in LIS, then L(i) 
can be recursively written as.
L(i) = { 1 + Max ( L(j) ) } where j < i and arr[j] < arr[i] and 
if there is no such j then L(i) = 1
To get LIS of a given array, we need to return max(L(i)) where 0 < i < n
So the LIS problem has optimal substructure property as the main problem 
can be solved using solutions to subproblems.

*/


/* 
Recursive Implementation

To make use of recursive calls, this function must return two things:
   1) Length of LIS ending with element arr[n-1]. We use max_ending_here 
      for this purpose
   2) Overall maximum as the LIS may end with an element before arr[n-1] 
      max_ref is used this purpose.
The value of LIS of full array of size n is stored in *max_ref which is our final result
*/

int _lis( int arr[], int n, int *max_ref)
{
    /* Base case */
    if(n == 1)
        return 1;
 
    int res, max_ending_here = 1; // length of LIS ending with arr[n-1]
 
    /* Recursively get all LIS ending with arr[0], arr[1] ... ar[n-2]. If 
       arr[i-1] is smaller than arr[n-1], and max ending with arr[n-1] needs
       to be updated, then update it */
    for(int i = 1; i < n; i++)
    {
        res = _lis(arr, i, max_ref);
        if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    // Compare max_ending_here with the overall max. And update the
    // overall max if needed
    if (*max_ref < max_ending_here)
       *max_ref = max_ending_here;
 
    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}


/* 
The same solution 
using dynamic programming
*/

/* lis() returns the length of the longest increasing subsequence in 
    arr[] of size n */
int lis( int arr[], int n )
{
   int *lis, i, j, max = 0;
   lis = (int*) malloc ( sizeof( int ) * n );
 
   /* Initialize LIS values for all indexes */
   for ( i = 0; i < n; i++ )
      lis[i] = 1;
    
   /* Compute optimized LIS values in bottom up manner */
   for ( i = 1; i < n; i++ )
      for ( j = 0; j < i; j++ )
         if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;
    
   /* Pick maximum of all LIS values */
   for ( i = 0; i < n; i++ )
      if ( max < lis[i] )
         max = lis[i];
 
   /* Free memory to avoid memory leak */
   free( lis );
 
   return max;
}

/* 
Time complexity is O(n^2)
