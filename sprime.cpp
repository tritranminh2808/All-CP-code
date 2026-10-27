#include <bits/stdc++.h>
using namespace std; 
using u64 = unsigned long long;
u64 mp(u64 a,u64 b,u64 m){ u64 r=1; for(a%=m;b;b>>=1,a=(__uint128_t)a*a%m) if(b&1) r=(__uint128_t)r*a%m; return r; }
bool p(u64 n){ if(n<2||n%2==0) return n==2; u64 d=n-1, s=__builtin_ctzll(d); d>>=s;
    for(u64 a: {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL}){
        if(a % n == 0) continue;
        u64 x = mp(a, d, n);
        if(x==1 || x==n-1) continue;
        bool ok=0;
        for(u64 i=1;i<s;i++) if((x=(__uint128_t)x*x%n)==n-1){ ok=1; break; }
        if(!ok) return 0;
    }
    return 1;
}

vector<u64> v; u64 l, r;
void f(u64 x, u64 m){
    if(x>r) return;
    v.push_back(x);
    for(int d=1; d<=9; d++){
        u64 y = d*m + x;
        if(y<=r && p(y)) f(y, m*10);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>l>>r;
    for(u64 x: {2,3,5,7}) f(x, 10);
    sort(v.begin(), v.end());
    cout<<count_if(v.begin(), v.end(), [](u64 x){ return x>=l; });
    return 0;
}

