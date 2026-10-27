#include <bits/stdc++.h>
#define int long long
using namespace std;
int spf[500005], mu[500005], cnt[500005], a[200005];
vector<int> ds[200005];
bool xh[200005];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    mu[1]=1;
    for(int i=2;i<=500000; i++){
        if(spf[i]) continue;
        for(int j=i;j<=500000;j+=i) if(!spf[j]) spf[j]=i;
    }
    for(int i=2;i<=500000;i++){
        int p=spf[i], m=i/p;
        if(m%p==0) mu[i]=0;
        else mu[i]=-mu[m];
    }
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        int x=a[i];
        vector<pair<int,int>> f;
        while(x > 1){
            int p=spf[x],c=0;
            while(x%p==0){
                x/=p;
                c++;
            }
            f.push_back({p,c});
        }
        ds[i]={1};
        for(auto &t:f){
            int p=t.first,c=t.second;
            int sz = ds[i].size(), m=1;
            for(int e=1;e<=c;e++){
                m*=p;
                for(int j=0;j<sz;j++) ds[i].push_back(ds[i][j] * m);
            }
        }
    }
    int sol=0;
    while(q--){
        int k;
        cin >> k;
        if(!xh[k]){
            for(int i:ds[k]){
                sol+=mu[i]*cnt[i];
                cnt[i]++;
            }
            xh[k]=1;
        } 
        else {
            for(int i:ds[k]){
                cnt[i]--;
                sol-=mu[i]*cnt[i];
            }
            xh[k]=0;
        }
        cout << sol << "\n";
    }

    return 0;
}
