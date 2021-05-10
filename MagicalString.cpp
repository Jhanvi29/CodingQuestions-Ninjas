#include <bits/stdc++.h>
using namespace std;
string magicalString(string &s){
	// Write your code here.
    stack<char> st;
    int i=0;
    while(i < s.length()){
        if(!st.empty() && abs(s[i] - st.top()) == 32){
            st.pop();
            i++;
        }
        else {
            st.push(s[i]);
            i++;
        }
        
    }
        string short_string = ""; 
        while (!st.empty())
        {
            short_string = st.top() + 
                           short_string;
            st.pop();
        }
        return (short_string);   
}

//Write main function accordingly
