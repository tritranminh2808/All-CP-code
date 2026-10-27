#include <bits/stdc++.h>
using ll = long  long ;
using namespace std;
const int MAXN=4e6+2;
long long n,m,k,dem,a[MAXN],b[MAXN],x=1;
bool c[MAXN];
 int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    long long x=1,m=n;
    while(n--)
    {
        if(n>0)x*=n;
    }
    long long x1=x;
    n=m;
    m=n-1;
    long long ans=1;
    for(int i=1;i<=n;i++)
    {
        c[a[i]]=true;
        long long dem=0;
        for(int j=1;j<a[i];j++)
        {
            if(!c[j])dem++;
        }
        ans+=dem*x;
        if(m>0)x/=m;
        m--;
    }
    long long y;
    cin>>y;
    long long dem1=0;
    m=n-1;
    fill(c,c+100,false);
    while(n--)
    {
        long long z=y;
        for(int i=1;y-1>=0;i++)
            {
                if(!c[i])y-=x1;
                if(y-1<0)b[dem1++]=i;
            }
        c[b[dem1-1]]=true;
        y+=x1;
        if(m>0)x1/=m;
        m--;
    }
    cout<<ans<<"\n";
    for(int i=0;i<dem1;i++) cout<<b[i]<<" ";
}
