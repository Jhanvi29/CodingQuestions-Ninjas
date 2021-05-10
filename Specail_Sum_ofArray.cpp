#include <bits/stdc++.h>
using namespace std;

int digSum(int n)
{
    int sum = 0;
    
    // Loop to do sum while
    // sum is not less than
    // or equal to 9
    while(n > 0 || sum > 9)
    {
        if(n == 0)
        {
            n = sum;
            sum = 0;
        }
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int sum(int *arr, int size)
{
	// Write code here
    
    if(size == 1){
        return arr[0];
    }
    int s = 0;
    for(int i=0; i<size; i++){
        s = s + arr[i];
    }
    int d = digSum(s);
 	return d;
    
}