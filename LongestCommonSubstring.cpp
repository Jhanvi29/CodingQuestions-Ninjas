int lcs(string &str1, string &str2)
{
	//	Write your code here.
    int m = str1.size();
    int n = str2.size();
    
    int table[m+1][n+1];
    int result = 0;
    
    for(int i=0; i<=m; i++){
        for(int j =0; j<=n; j++){
            if(i==0 || j==0)
                table[i][j] = 0;
            else if(str1[i-1] == str2[j-1]){
                table[i][j] = 1+table[i-1][j-1];
                result = max(result,table[i][j]);
           }
           else 
               table[i][j] = 0;
        }
    }
    return result;
}
