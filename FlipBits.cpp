/* You are given an array of integers ARR[] of size N consisting of zeros and ones. You have to select a subset and flip bits of that subset. You have to return the count of maximum one’s that you can obtain by flipping chosen sub-array at most once.
A flip operation is one in which you turn 1 into 0 and 0 into 1.
For example: If you are given an array {1,1,0,0,1} then you will have to return the count of maximum one’s you can obtain by flipping anyone chosen sub-array at most once, so here you will clearly choose sub-array from the index 2 to 3 and then flip it's bits. 
So, the final array comes out to be {1,1,1,1,1} which contains five ones and so you will return 5.*/


int flipBits(int* arr, int n) 
{
	// WRITE YOUR CODE HERE
	int orig_zero_count = 0;

	// Initiale overall max diff for any subarray
	int max_diff = 0;

	// Initialize current diff
	int curr_max = 0;

	for (int i=0; i<n; i++)
	{
		// Count of zeros in original array (Not related
		// to Kadane's algorithm)
		if (arr[i] == 1)
		orig_zero_count++;

		// Value to be considered for finding maximum sum
		int val = (arr[i] ==0)? 1 : -1;

		// Update current max and max_diff
		curr_max = max(val, curr_max + val);
		max_diff = max(max_diff, curr_max);
	}
	max_diff = max(0, max_diff);

	return orig_zero_count + max_diff;
    
}
