#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        int n;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            int g;
            cin>>g;
            v.push_back(g);
        }
        int q=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            ans.push_back(v[i]);
            else
            {
                int p=ans[i-1]+v[i];
                int y=ans[i-1]-v[i];
                if(p!=y && y>=0)
                {
                    q=1;
                    break;
                }
                else
                {
                    ans.push_back(p);
                }
            }
        }
        if(q==1)
        cout<<-1<<endl;
        else
        {
            for(int i=0;i<n;i++)
            {
                cout<<ans[i]<<" ";
            }        
            cout<<endl;    
        }
    }
}