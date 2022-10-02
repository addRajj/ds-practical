#include<bits/stdc++.h>
using namespace std;
bool isoperator(char c)
{
    if(c=='*' || c=='+' || c=='-' || c=='/')
    return true;
    else
    return false;
}
void pretopost(string s)
{
    stack<string>st;
    reverse(s.begin(), s.end());
    for(int i=0;i<s.size();i++)
    {
        if(isoperator(s[i]))
        {
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            string temp=s1 + s2+ s[i];
            st.push(temp);
        }
        else
        {
            string t(1, s[i]);
            st.push(t);
        }
    }
    cout<<st.top();

}
int main()
{
    cout<<"Enter the String to Convert From Prefix to Postfix: ";
    cout<<endl;
    string s;
    cin>>s;
    cout<<"The result is as follows:"<<endl;
    pretopost(s);
}