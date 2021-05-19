/*
You have been given two strings “str1” and “str2” of characters. Your task is to find the length of the longest common subsequence.
A string ‘a’ is a subsequence of a string ‘b’ if ‘a’ can be obtained from ‘b’ by deletion of several (possibly, zero or all) characters.
A common subsequence of two strings is a subsequence that is common to both strings. */

#include<bits/stdc++.h> 
using namespace std;
int getLengthOfLCS(string &str1, string &str2)
{
	//    Write your code here.
    int m = str1.length();
    int n = str2.length();
    
    int t[m+1][n+1];
    
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j ==0)
                t[i][j] = 0;
            else if(str1[i-1] == str2[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
        }
    }
    
    return t[m][n];
}
    
