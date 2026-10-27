#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using i64 = long long;
using f64 = long double;
using ui64 = unsigned long long;
using pII = pair<int,int>;
using pLL = pair<i64,i64>;
int L,R,mp[1000009],Raven[1000009],c=0;
i64 res=0;
int biggest_sq_free(int n)
{
    int prod=1;
    while(n>1)
    {
        if(prod%mp[n]) prod*=mp[n];
        n/=mp[n];
    }
    return prod;
}
signed main()
{
    freopen("SAMEPAIR006.inp","r",stdin);
	freopen("SAMEPAIR006.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=2;i<=1000;++i)
    {
        if(!mp[i])
        {
            for(int j=i*i;j<=1000000;j+=i)
                if(!mp[j]) mp[j]=i;
        }
    }
    for(int i=2;i<=1000000;++i)
        if(!mp[i]) mp[i]=i;
    cin>>L>>R;
    for(int i=L;i<=R;++i) Raven[++c]=biggest_sq_free(i);
    sort(Raven+1,Raven+c+1);
    for(int i=1,j=1;i<=c;i=j)
    {
        while(Raven[i]==Raven[j]) ++j;
        res+=1LL*(j-i)*(j-i-1)/2;
    }
    cout<<res;
}
