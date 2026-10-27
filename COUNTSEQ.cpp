#include <bits/stdc++.h>
using namespace std;
long long t,S;
const long long mod=1e9+7;
map<long long,long long> dp;
vector<long long> u;
void sinh_uoc(long long x)
{
    for(long long i=1;i*i<=x;++i)
    {
        if(x%i==0)
        {
            u.push_back(i);
            if(i!=x/i) u.push_back(x/i);
        }
    }
    sort(u.begin(),u.end());
}
long long luy_thua(long long x,long long y)
{
    long long r=1;
    while(y>0)
    {
        if(y%2==1) r=r*x%mod;
        x=x*x%mod; y/=2;
    }
    return r;
}
void sol()
{
    cin >> S;
    dp.clear(); u.clear();
    sinh_uoc(S); dp[1]=1;
    for(long long i=1;i<u.size();++i)
    {
        dp[u[i]]=luy_thua(2,u[i]-1);
        for(long long j=i-1;j>=0;--j)
            if(u[i]%u[j]==0) dp[u[i]]=(dp[u[i]]-dp[u[j]])%mod;
    }
    cout<<(dp[S]+mod)%mod<<"\n";
}
int  main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    for(long long i=0;i<t;i++) sol();
    return 0;
}
