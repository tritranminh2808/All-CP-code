#include <bits/stdc++.h>
using namespace std;
int n,m,q;
string a,b;
int f1[30][100005],f2[30][100005];
void cok(int l1, int r1, int l2 ,int r2){
    if(r1-l1!=r2-l2){
        cout << "NO\n";
        return;
    }
    int ns1=f1[27][r1]-f1[27][l1-1],ns2=f2[27][r2]-f2[27][l2-1];
    for(int i=0;i<=26;i++){
        int cnt1=f1[i][r1]-f1[i][l1-1],cnt2=f2[i][r2]-f2[i][l2-1];
        if(cnt1>cnt2) {
            ns2-=cnt1-cnt2;
            if(ns2<0) {
                cout << "NO\n";
                return ;
            }
        }
        else if(cnt1<cnt2){
            ns1-=cnt2-cnt1;
            if(ns1<0){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    cin >> a >> b;
    a='!'+a;
    b='!'+b;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=27;j++) f1[j][i]=f1[j][i-1];
        if(a[i]=='?') f1[27][i]++;
        else f1[a[i]-'a'][i]++;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<=27;j++) f2[j][i]=f2[j][i-1];
        if(b[i]=='?') f2[27][i]++;
        else f2[b[i]-'a'][i]++;
    }
    while(q--){
        int l1,r1,l2,r2; cin >> l1 >> r1 >> l2 >> r2;
        cok(l1,r1,l2,r2);
    }
    return 0;
}