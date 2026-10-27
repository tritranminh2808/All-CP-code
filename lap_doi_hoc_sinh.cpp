#include <bits/stdc++.h>
using namespace std;
bool scp(int x){
    int k=sqrt(x);
    return k*k==x;
}
void cok(){
    int n,m; cin >> n >> m;
    vector <int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a.begin()+1,a.end());
    unordered_map<int, int > mp;
    int l=1;
    int ans=INT_MAX;
    for(int r=1;r<=n;r++){
        int x=a[r];
        // cout << a[l] << " " << a[r] << "\n";
        for(int j=1;j<sqrt(x);j++){
            if(x%j==0){
                int p=x/j;
                if(j<=m)mp[j]++;
                if(p<=m)mp[p]++;
            }
        }
        if(scp(x)&&sqrt(x)<=m) mp[sqrt(x)]++;
        // if(mp.size()==m) 
        while(mp.size()==m){
            int y=a[l];
            ans=min(ans,a[r]-a[l]);
            for(int j=1;j<sqrt(y);j++){
                if(y%j==0){
                    int p=y/j;
                    if(j<=m){
                        mp[j]--;
                        if(mp[j]==0) mp.erase(j);
                    }
                    if(p<=m){
                        mp[p]--;
                        if(mp[p]==0) mp.erase(p);
                    }
                }
            }
            if(scp(y)&&sqrt(y)<=m) {
                mp[sqrt(y)]--;
                if(mp[sqrt(y)]==0) mp.erase(sqrt(y));
            }
            l++;
        }
    }
    if(ans!=INT_MAX)cout << ans << "\n";
    else cout << "-1\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cok();
    }
    return 0;
}