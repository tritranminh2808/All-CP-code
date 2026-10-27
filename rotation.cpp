#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,K; string s;
    cin>>n>>K>>s;
    vector<int> d;
    for(int i=1;i<=n;i++) if(n%i==0) d.push_back(i);
    int r=n;
    for(int p:d){
        int t=0;
        for(int i=0;i<p;i++){
            vector<int> c(26);
            int sz=0, m=0;
            for(int j=i;j<n;j+=p){
                c[s[j]-'a']++;
                sz++;
            }
            for(int x=0;x<26;x++) m=max(m, c[x]);
            t+=sz-m;
        }
        if(t<=K) r=min(r, p);
    }
    cout<<r;
    return 0;
}

