#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
int n,q;
vector<int>a;
ll p(int b,int e){
    ll r=1;
    while(e){
        if(e&1)r=r*b%mod;
        b=1LL*b*b%mod;
        e>>=1;
    }
    return r;
}
ll c(){
    ll s=accumulate(a.begin(),a.end(),0LL);
    return p(s,1+n/2);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    a.resize(n);
    for(int&i:a)cin>>i>>q;
    cout<<c()%mod;
}

