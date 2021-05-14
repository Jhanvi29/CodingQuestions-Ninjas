/*
Problem Statement
You are given an array of integers of length N, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can negative numbers as well.
For example, the input [3, 4, -1, 1] should give output 2 because it is the smallest positive number that is missing in the input array.
Input Format:
The first line of input contains a single integer T, representing the number of test cases or queries to be run. 
Then the T test cases follow.

The first line of each test case contains a positive integer N which represents the length of the array.

The Second line of each test case contains N integers representing the elements of the array.
Output Format :
For each test case, return the minimum positive integer that is missing from the given input array.
Note:
You do not need to print anything. It has already been taken care of.
Constraint :
1 <= T <= 10
1 <= N <= 10^5
-10^5 <= arr[i] <= 10^5

Time Limit: 1 sec
Sample Input 1 :
1
5
3 2 -6 1 0
Sample Output 1:
4
Explanation For Input 1:
The first positive number is 1 and it is present in the array similarly 2 and 3 are also present in the array. 4 is missing from the array. Thus, the minimum positive integer that is missing is 4.
Sample Input 2 :
1
5
0 1 2 3 4
Sample Output 2:
5
Previous
Next
*/

Algorithm


Segregation
Call a function that will segregate the positive integer to the negative integers i.e move all non-positive elements to the right side, and return the index at which non-positive integers start.
Now we can ignore non-positive elements and consider only the part of the array which contains all positive elements. We traverse the array containing all positive numbers. To mark the presence of an element arr[i], we change the sign of value at index arr[i] to negative i.e mark the presence of element 1 by making the element of array at index 1 to negative, given that the index lies in that segment of positive elements.
To find the smallest positive missing element, we traverse the positive elements array again and print the first index which has positive value. In case all elements are negative, our index is size - 1. We subtract 1 from the index and that would be the answer.
Time Complexity
O(N), where N is the length of the array, as we are traversing the array.

Space Complexity
O(1), Where N is the length of the array, as we are not using any extra space.

Previous
Next



#include <bits/stdc++.h>
using namespace std;
 
/* Utility to swap to integers */
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
 
/* Utility function that puts all
non-positive (0 and negative) numbers on left
side of arr[] and return count of such numbers */
int segregate(int arr[], int size)
{
    int j = 0, i;
    for (i = 0; i < size; i++) {
        if (arr[i] <= 0) {
            swap(&arr[i], &arr[j]);
           
            // increment count of
            // non-positive integers
            j++;
        }
    }
 
    return j;
}
 
/* Find the smallest positive missing number
in an array that contains all positive integers */
int findMissingPositive(int arr[], int size)
{
    int i;
 
    // Mark arr[i] as visited by
    // making arr[arr[i] - 1] negative.
    // Note that 1 is subtracted
    // because index start
    // from 0 and positive numbers start from 1
    for (i = 0; i < size; i++) {
        if (abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }
 
    // Return the first index
    // value at which is positive
    for (i = 0; i < size; i++)
        if (arr[i] > 0)
           
            // 1 is added because
            // indexes start from 0
            return i + 1;
 
    return size + 1;
}
 
/* Find the smallest positive missing
number in an array that contains
both positive and negative integers */
int firstMissing(int arr[], int size)
{
     
    // First separate positive
    // and negative numbers
    int shift = segregate(arr, size);
 
    // Shift the array and call
    // findMissingPositive for
    // positive part
    return findMissingPositive(arr + shift,
                               size - shift);
}
