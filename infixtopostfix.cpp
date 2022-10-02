#include<bits/stdc++.h>
using namespace std;
int perc(char c)
{
    if(c=='^')
    return 3;
    else if(c=='*' || c=='/')
    return 2;
    else if(c=='+' || c=='-')
    return 1;
    else
    return  -1;
}
string  infitopost(string s)
{
    string ans="";

    stack<char>st;
    
    for(int i=0;i<s.size();i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        {
            ans+=s[i];        
        }
        else if(s[i]=='(')
        {
            st.push('(');
        }
        else if(s[i]==')')
        {
            while(st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(st.size()!=0 && (perc(s[i])<=perc(st.top())))
            {
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(st.size()!=0)
    {
        ans+=st.top();
        st.pop();
    }

    return ans;
}

string infitopre(string s)
{
    string p=s;
    reverse(p.begin()   , p.end());
    for(int i=0;i<p.size();i++)
    {
        if(p[i]=='(')
        p[i]=')';
        else if(p[i]==')')
        p[i]='(';
    }

    string x=infitopost(p);
    reverse(x.begin() , x.end());

    return x;

}

int main()
{
    cout<<"enter the Infix Expression";
    cout<<endl;
    string s;
    cin>>s;
    cout<<"The Infix to Postfix Conversion is as follow: ";
    cout<<infitopost(s);
    cout<<endl;
    cout<<"The Infix to Prefix conversion is as follow: ";
    cout<<infitopre(s);
}
