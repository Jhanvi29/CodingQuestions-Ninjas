/*Problem Statement
Ninja has been given a binary string ‘STR’ containing either ‘0’ or ‘1’. A binary string is called beautiful if it contains alternating 0s and 1s.
For Example:‘0101’, ‘1010’, ‘101’, ‘010’ are beautiful strings.
He wants to make ‘STR’ beautiful by performing some operations on it. In one operation, Ninja can convert ‘0’ into ‘1’ or vice versa.
Your task is to determine the minimum number of operations Ninja should perform to make ‘STR’ beautiful.
For Example: Minimum operations to make ‘STR’ ‘0010’ beautiful is ‘1’. In one operation, we can convert ‘0’ at index ‘0’ (0-based indexing) to ‘1’. 
The ‘STR’ now becomes ‘1010’ which is a beautiful string.
*/


char flips(char ch){
    return (ch == '0') ? '1' : '0';
}

int findflips(string str, char ch){
    int f=0;
    for(int i=0 ;i<str.length(); i++){
        if(str[i] != ch){
            f++;
        }
        ch = flips(ch);
    }
    
    return f;
}


int makeBeautiful(string str) {
    
	// Write your code here
    return min(findflips(str,'0'), findflips(str,'1'));
}
