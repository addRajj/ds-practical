#include<bits/stdc++.h>
using namespace std;
int main()
{

    cout<<"Enter the string - to check if its a palindrome or not"<<endl;
    
    string s; // creating a string
    cin>>s;  

    stack<char>st; //creating a stack

    for(int i=0;i<s.size();i++)
    {
        if(st.empty())
        st.push(s[i]);
        else
        {
            
            if(s[i]=='}' && st.top()=='{')       // Checking for the balanced pairs 
            st.pop();
            else if(s[i]==')' && st.top()=='(')  // Checking for the balanced pairs 
            st.pop();
            else if(s[i]==']' && st.top()=='[')  // Checking for the balanced pairs 
            st.pop();
            else
            st.push(s[i]);

        }
    }

    if(st.size()==0)
    cout<<"YES! The Entered String Is A Palindrome"<<endl;
    else
    cout<<"NOPE! The Given String Is Not A Palindrome"<<endl;
}