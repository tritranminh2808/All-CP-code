#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
using ui64 = unsigned long long;
mt19937 rng32(time(0));
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
i64 t,n,k,m;
bool state[100009];
struct Package{
    i64 a,b;
}book[100009];
struct cmp{
    bool operator()(pair<i64,int> x,pair<i64,int> y){
        return x.first>y.first;
    }
};
priority_queue<pair<i64,int>,vector<pair<i64,int>>,cmp> A,B;
priority_queue<i64,vector<i64>,greater<i64>> C;
void XL()
{
    cin>>n>>k>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>book[i].a>>book[i].b;
        state[i]=false;
    }
    for(int i=1;i<=n;++i)
    {
        A.push({book[i].a,i}); //Expensive
        B.push({book[i].b,i}); //Cheap
    }
    for(int i=1;i<=k;++i) C.push(0);
    int res=0;
    while(m>0 and res<n)
    {
        while(!A.empty() and state[A.top().second]) A.pop();
        while(!B.empty() and state[B.top().second]) B.pop();
        if(C.top()+B.top().first<A.top().first)
        {
            i64 cost=C.top()+B.top().first;
            if(cost>m) break;
            m-=cost; C.pop();
            C.push(book[B.top().second].a-book[B.top().second].b);
            state[B.top().second]=true;
        }
        else
        {
            if(A.top().first>m) break;
            m-=A.top().first;
            state[A.top().second]=true;
        }
        ++res;
    }
    cout<<res;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    t=1;//cin>>t;
    while(t--) XL();
}
