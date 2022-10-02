#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter the string to Evaluate - POSTFIX"<<endl;
    string s;
    cin>>s;
    stack<int>st;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            st.push(s[i]-'0');
        }
        else
        {
            int g=st.top();
            st.pop();
            int l=st.top();
            st.pop();
            int res;
            if(s[i]=='+')
            {
                res=g+l;
                st.push(res);
            }
            else if(s[i]=='-')
            {
                res=g-l;
                st.push(res);
            }
            else if(s[i]=='*')
            {
                res=g*l;
                st.push(res);
            }
            else if(s[i]=='/')
            {
                res=g/l;
                st.push(res);
            }
        }
    }
    cout<<"the desired result is : "<<st.top()<<endl;
}