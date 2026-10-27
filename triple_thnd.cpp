#include <bits/stdc++.h>
using namespace std;
const int pp=1e7+1;
int snt[pp];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n; 
    cin >> n;
    for(int i=2;i<=n;++i) 
    {
        if(snt[i]) continue;
        for(int j=i;j<=n;j+=i)
            if(!snt[j]) snt[j]=i;
    }
    unordered_map<int,long long> cnt;
    for(int i=1;i<=n;++i){
        int t=i,ss=1;
        while(t>1){
            int p=snt[t], d=0;
            while(t%p==0){ 
                t/=p; 
                ++d; 
            }
            if(d%2==1) ss*=p;
        }
        cnt[ss]++;
    }
    long long res = 0;
    for(auto i:cnt){
        long long k=i.second;
        res+=k*(k-1)*(k-2)/6;
    }
    cout << res;
    return 0;
}