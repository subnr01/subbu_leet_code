/*

Given an unsorted array of numbers, write a function that returns true if array consists of consecutive numbers. 
Examples: a) If array is {5, 2, 3, 1, 4}, then the function should return true because the 
array has consecutive numbers from 1 to 5. 
b) If array is {83, 78, 80, 81, 79, 82}, then the function should return true because the array has 
consecutive numbers from 78 to 83. 
c) If the array is {34, 23, 52, 12, 3 }, then the function should return false because the elements 
are not consecutive. 
d) If the array is {7, 6, 5, 5, 3, 4}, then the function should return false because 5 and 5 are 
not consecutive.


*/

/*

Solution
Method 1 (Use Sorting) 
1) Sort all the elements. 
2) Do a linear scan of the sorted array. If the difference between current element and next element is 
anything other than 1, then return false. If all differences are 1, then return true. 
Time Complexity: O(nLogn) 

Method 2 (Use visited array) 
The idea is to check for following two conditions. If following two conditions are true, then return true
1) max – min + 1 = n where max is the maximum element in array, min is minimum element in array and n is the 
number of elements in array. 
2) All elements are distinct. 
To check if all elements are distinct, we can create a visited[] array of size n. We can map the ith element of 
input array arr[] to visited array by using arr[i] – min as index in visited[].

*/

