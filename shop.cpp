#include<bits/stdc++.h>
using namespace std; using ll=long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,x; 
	cin >> n >> k >> x;
    vector <ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    ll cnt=0;
    for(int i=1;i<=n;i++) cnt+=a[i];
    ll maxx=0;
    vector<int> f(k);
    for(int i=0;i<x;i++) f[k-1-i]=1; 
    do{
        vector<int> b(n+1);
        for(int i=1;i<=k;i++) b[i]=f[i-1];
        int s=0;
        for(int i=2;i<=k;i++) s+=b[i];
        bool ok=1;
        for(int i=k+1;i<=n;i++){
            int v=x-s;
            if(v<0||v>1){ 
				ok=0; 
				break;
			}
            b[i]=v;
            s+=b[i]-b[i-k+1];
        }
        if(ok){
            ll sf=0;
            for(int i=1;i<=n;i++) if(b[i]) sf+=a[i];
            maxx=max(maxx, sf);
        }
    } while(next_permutation(f.begin(), f.end()));
    cout<< cnt-maxx;
}

