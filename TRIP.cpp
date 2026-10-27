#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#pragma GCC optimize ("O3,unroll-loops")
using namespace std;
long long n,x,m,k=0,t=0,p=1e16;
map<int,int> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>x;
    vector<int> A(n);
    for (int i=0;i<n;++i) {
        cin>>m;
        m%=x;
        m=x-m;
        k+=m;
        A[i]=m;
    }
    sort(A.begin(),A.end());
    for (int i=0;i<n;++i) ++s[A[i]];
    for (const auto&pair:s) {
        p=min(p,k-n*pair.first+x*t);
        t+=pair.second;
    }
    cout<<p;
}
