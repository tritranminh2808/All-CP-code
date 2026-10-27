#include <bits/stdc++.h>
using namespace std;
#define int long long
int st[200005];
int n,k;
void cok(){
    cin >> n >> k;
    for(int i=1;i<=n;i++) st[i]=-1;
    string s; cin >> s;
    if(n==1&&s=="2"){
        cout << "-\n";
        return;
    }
    if(n==2&&s=="22"){
        cout << "--\n";
        return;
    }
    int l=0,r=0,x=0;
    for(auto i:s){
        if(i=='0') l++;
        else if(i=='1')r++;
        else x++; 
    }
    if(l+r+x>=n){
        for(int i=1;i<=n;i++) cout << "-";
        cout << "\n";
        return;
    }
    for(int i=1;i<=l;i++) st[i]=0;
    for(int i=n;i>=n-r+1;i--) st[i]=0;
    for(int i=l+x+1;i<=n-r-x;i++) if(i>=1&&i<=n) st[i]=1;
    for(int i=1;i<=n;i++){ 
        if(st[i]==1) cout << "+"; 
        else if(st[i]==-1) cout << "?"; 
        else cout << "-"; 
    } 
    cout << "\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) cok();
    return 0;
}