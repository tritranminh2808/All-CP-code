#include<bits/stdc++.h>
using namespace std;
int n,m,x,kq=1e9;
vector<int>luu[100008];
int a[100008],kc[100008],db[100008];
int u,v;
int main()
{
    cin>>n>>m>>x;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        luu[u].push_back(v);
        luu[v].push_back(u);
    }
    for(int i=1;i<=x;i++)
    {
        cin>>db[i];
    }
    queue<int>q;
    for(int i=1;i<=x;i++)
    {
        a[db[i]]=db[i];
        kc[db[i]]=0;
        q.push(db[i]);
    }
    while(!q.empty()&&kq>1)
    {
        u=q.front();
        q.pop();
        for(int v:luu[u])
        {
            if(a[v]==0)
            {
                a[v]=a[u];
                kc[v]=kc[u]+1;
                q.push(v);
            }
            else if(a[v]!=a[u])
            {
                kq=min(kq,kc[u]+kc[v]+1);
            }
        }
    }
    cout<<kq;
    return 0;
}
