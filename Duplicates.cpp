vector<int> findDuplicates(vector<int>&numRay, int arr_size) {
	// Write your code here.
    vector<int> v;
    // count the frequency
    for (int i = 0; i < arr_size; i++) {
        numRay[numRay[i] % arr_size]
            = numRay[numRay[i] % arr_size] + arr_size;
    }
    for (int i = 0; i < arr_size; i++) {
        if (numRay[i] >= arr_size * 2) {
            v.push_back(i);
        }
    }
    return v;
}
