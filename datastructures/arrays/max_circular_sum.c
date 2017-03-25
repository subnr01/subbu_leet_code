/*

Given n numbers (both +ve and -ve), arranged in a circle, fnd the maximum sum of consecutive number. 
Examples: 
Input: a[] = {8, -8, 9, -9, 10, -11, 12}
Output: 22 (12 + 8 - 8 + 9 - 9 + 10)

Input: a[] = {10, -3, -4, 7, 6, 5, -4, -1} 
Output:  23 (7 + 6 + 5 - 4 -1 + 10) 

Input: a[] = {-1, 40, -14, 7, 6, 5, -4, -1}
Output: 52 (7 + 6 + 5 - 4 - 1 - 1 + 40)

There can be two cases for the maximum sum:
Case 1: The elements that contribute to the maximum sum are arranged such that no wrapping is there. Examples: {-10, 2, -1, 5}, {-2, 4, -1, 4, -1}. In this case, Kadane’s algorithm will produce the result.

Case 2: The elements which contribute to the maximum sum are arranged such that wrapping is there. Examples: {10, -12, 11}, {12, -5, 4, -8, 11}. In this case, we change wrapping to non-wrapping. Let us see how. Wrapping of contributing elements implies non wrapping of non contributing elements, so find out the sum of non contributing elements and subtract this sum from the total sum. To find out the sum of non contributing, invert sign of each element and then run Kadane’s algorithm.
Our array is like a ring and we have to eliminate the maximum continuous negative that implies maximum continuous positive in the inverted arrays

*/


// The function returns maximum circular contiguous sum in a[]
int maxCircularSum (int a[], int n)
{
   // Case 1: get the maximum sum using standard kadane's algorithm
   int max_kadane = kadane(a, n);
 
   // Case 2: Now find the maximum sum that includes corner elements.
   int max_wrap  =  0, i;
   for(i=0; i<n; i++)
   {
        max_wrap += a[i]; // Calculate array-sum
        a[i] = -a[i];  // invert the array (change sign)
   }
 
   // max sum with corner elements will be:
   // array-sum - (-max subarray sum of inverted array)
   max_wrap = max_wrap + kadane(a, n);
 
   // The maximum circular sum will be maximum of two sums
   return (max_wrap > max_kadane)? max_wrap: max_kadane;
}
